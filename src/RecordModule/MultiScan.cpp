//
// Created by AlexFan on 2019/1/7.
//

#include "RecordModule/MultiScan.h"

using namespace RM;

ScanQuery::ScanQuery(int mCol, IM::CompOp cp, int vCol)
{
    queryType = RM::QueryType::DUAL;
    mainCol = mCol;
    compOp = cp;
    viceCol = vCol;
    target = RM::BOTH;
}

DualScan::~DualScan() {}

DualScan::DualScan(RM_FileHandle *mHandle, RM_FileHandle *vHandle){
    mainHandler = mHandle;
    viceHandler = vHandle;
    scanResult = new list<pair<RID, list<RID>>>();
}

int DualScan::CheckHandler()
{
    if(mainHandler == nullptr || viceHandler == nullptr)   {
        return 1;
    }
    return 0;
}

int DualScan::OpenScan(list<ScanQuery> queryList)
{
    if(CheckHandler()) {
        return 1;
    }
    RM_FileScan *mainScan = new RM_FileScan();
    RM_FileScan *viceScan = new RM_FileScan();
    RM_Record rec;
    scanResult = new list<pair<RID, list<RID>>>;
    mainScan->OpenScanAll(*mainHandler);
    int cnt = 0;
    for(auto iter = queryList.begin(); iter != queryList.end(); iter ++)
    {
        if(iter->queryType == QueryType::SINGLE && iter->target == ScanTarget::MAIN)
        {
            if(iter->scanType == RM::RangeScan) {
                mainScan->OpenScan(*mainHandler, iter->mainCol, iter->compOp, iter->keyValue);
            }
            else if(iter->scanType == RM::NullScan) {
                mainScan->OpenScan(*mainHandler, iter->mainCol, iter->isNull);
            }
        }
    }
    int mainResultNum = mainScan->ResultNum();
    while(mainScan->GetNextRec(*mainHandler, rec) != 1)
    {
        printf("%8d / %8d\r", cnt, mainResultNum);
        cnt ++;
        RID mainRid;
        rec.GetRid(mainRid);
        for(auto iter = queryList.begin(); iter != queryList.end(); iter ++)
        {
            if(iter->queryType == QueryType::SINGLE)
            {
                if(iter->target == ScanTarget::MAIN) {
                    continue;
                }
                else if(iter->target == ScanTarget::VICE) {
                    if(iter->scanType == RM::RangeScan) {
                        viceScan->OpenScan(*viceHandler, iter->viceCol, iter->compOp, iter->keyValue);
                    }
                    else if(iter->scanType == RM::NullScan) {
                        viceScan->OpenScan(*viceHandler, iter->viceCol, iter->isNull);
                    }
                }
            }
            else
            {
                int mCol = iter->mainCol, vCol = iter->viceCol;
                IM::CompOp compOp = iter->compOp;
                string colStr;
                bool isNull;
                if(mainHandler->recordHandler->GetColumnStr(rec, mCol, colStr, isNull)){
                    return 1;
                }
                char *cStr = (char*)colStr.c_str();
                // FIXME: Bug may occur, be aware
                viceScan->OpenScan(*viceHandler, vCol, compOp, cStr);
            }

        }
        RM_Record vRecord;
        RID vRid;
        list<RID> ridList;
        int scnt = 0;
        while(viceScan->GetNextRec(*viceHandler, vRecord) != 1)
        {
            scnt ++;
            vRecord.GetRid(vRid);
            ridList.push_back(vRid);
        }
        if(!ridList.empty()) {
            pair<RID, list<RID>> item(mainRid, ridList);
            scanResult->push_back(item);
        }
        viceScan->CloseScan();
    }
    curResult = scanResult->begin();
    int sz = scanResult->size();
    return 0;
}

int DualScan::GetNextPair(pair<RID, list<RID>> &item) 
{
    if(curResult == scanResult->end()) {
        return 1; 
    }
    item = *curResult;
    curResult ++;
    return 0;
}

int DualScan::CloseScan() 
{
    if(scanResult != nullptr) {
        delete scanResult; 
    }
    scanResult = nullptr;
}
