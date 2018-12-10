#ifndef RM_FILEHANDLE_H
#define RM_FILEHANDLE_H
#include "RID.h"
#include "RM_Record.h"
#include "../fileio/FileManager.h"
#include "../bufmanager/BufPageManager.h"
#include "../utils/pagedef.h"
#include "../utils/MyBitMap.h"
#include "../IndexModule/IndexHandle.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>


using namespace bpt;
using namespace std;

class RM_FileHandle {
private:
    int fileId;
    int recordSize;
    int recordPP;
    int recordSum;
    int pageCnt;
    int recordMapSize;
	int firstPageBufIndex;
	int bufLastIndex = -1;
	int colNum;
	uint* pageUintMap;
	uint* recordUintMap;
    MyBitMap* pageBitMap;
    MyBitMap* recordBitMap;//current reading page's map
    BufPageManager *mBufpm;
	BufType readBuf;
	string indexPath;
	vector<string> title;
	vector<int> type;
	bool isValidChar(uint c);

public:
	IM::IndexHandle *indexHandle;
    RM_FileHandle();
    RM_FileHandle(int id, int sz);
    ~RM_FileHandle();                                  // Destructor
	int updateHead();
	RM_FileHandle(BufPageManager* bufpm, int fd, int rcz);
    int GetRec(const RID &rid, RM_Record &rec);
    int init(int _fileId, BufPageManager* _bufpm, char *indexName);
    // Get a record
    int InsertRec(RM_Record& pData);       // Insert a new record,
    //   return record id
    int DeleteRec(const RID &rid);                    // Delete a record
    int UpdateRec(const RM_Record &rec);
    int RecordNum() const;
    int PageNum() const {return pageCnt;}
    void SetTitle(vector<string> t);
    void PrintTitle();
    void SetFilePath();
    void SetType(vector<int> tp);
    vector<int> GetType();
    void show();
	int GetSlot(BufType page);
	static int CreateDir(string dirPath);
    // int ForcePages     (PageNum pageNum = ALL_PAGES) const; // Write dirty page(s)
};

#endif