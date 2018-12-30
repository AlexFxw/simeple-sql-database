#include "RecordModule/RM_Manager.h"
#include "RecordModule/RM_FileHandle.h"
#include "RecordModule/RecordHandler.h"
#include "RecordModule/RM_FileScan.h"
#include "RecordModule/RM_Record.h"
#include "IndexModule/IndexHandle.h"
#include "utils/MyBitMap.h"
#include "IndexModule/bpt.h"
#include "CommandModule/dataBaseManager.h"
#include <vector>
#include <string>

// 原先声明在头文件里的全局变量。。。
int current = 0;
int tt = 0;
unsigned char h[61];

using namespace std;

void NewTest()
{
    cout << "NewTest" << endl;
	char *dbName = "NewTest11";
	// Test for create DB
	CreateDB(dbName);
	DIR *dir = UseDB(dbName);
	if(dir == NULL) {
		cout << "Error in opening database." << endl;
		return;
	}
	RM_Manager *rmg = new RM_Manager(dbName);
	RM_FileHandle *handler = new RM_FileHandle();
	rmg->createFile(dbName, 3, 2);
	string test = rmg->openFile(dbName, *handler) ? "successfully opened" : "fail to open";
	cout << test << endl;

	vector<string> title;
	title.push_back("person");
	title.push_back("id");

	vector<RM_node> items;
	RM_node person_a("alexfan");
	RM_node id_a(2);
	items.push_back(person_a);
	items.push_back(id_a);

	handler->recordHandler = new RM::RecordHandler(2);

	handler->recordHandler->SetItemAttribute(0, 8, RM::CHAR, false);
	handler->recordHandler->SetItemAttribute(1, 1, RM::INT, true);

	RM_Record record;
	if(handler->recordHandler->MakeRecord(record, items)) {
		cout << "Error to make record." << endl;
	}

	handler->recordHandler->PrintRecord(record);
	handler->InsertRec(record);
}
/*
void Test(){
    vector<RM_node> vec;
    vector<string> title;
    vector<int> type;
    cout << "Please input 2 titles" << endl;
    string tmp;
    int recordSize = 2 * ITEM_LENGTH/4;
    for(int i = 0; i < 2; i ++) {
        cin >> tmp;
        title.push_back(tmp);
        type.push_back(STR_TYPE);
    }
    RM_Manager *rmg = new RM_Manager("test");
    RM_FileHandle *handler = new RM_FileHandle();
    // rmg->createFile("helloworld2", recordSize);
    string test = rmg->openFile("helloworld2", *handler) ? "successfully opened" : "fail to open";
    int cnt = 3;
    handler->PrintTitle();
    handler->SetTitle(title);
    // handler->SetType(type);
    type = handler->GetType();
    RM_Record *record = new RM_Record(type);
    cout << test << endl;
    RM_Record pData, nData;
    RID rid;
    while(cnt --) {
        vec.clear();
        cout << "Please input 2 items" << endl;
        for(int i = 0; i < 2; i ++) {
            cin >> tmp;
            RM_node node;
            node.setCtx(tmp);
            vec.push_back(node);
        }
        BufType buf = new uint;
        if(record->GetSerializeRecord(&buf, vec, recordSize)){
            cout << "error" << endl;
        }
        pData.SetType(type);
        pData.SetRecord(buf, recordSize, RID(1,0));
        handler->InsertRec(pData);
        if(pData.GetRid(rid)) {
            cout << "error to get rid" << endl;
        }
        handler->GetRec(rid, nData);
    }
    handler->DeleteRec(rid);
    RM_FileScan *fileScan = new RM_FileScan(type);
    handler->PrintTitle();
    fileScan->OpenScan(*handler, 0, 0, 0);
    IM::IndexHandle *indexHandle = handler->indexHandle;
    // FIXME: Should not directly call in main
    vector<RID> tmpvec;
    char *left = "aa";
    char *right = "cc";
    indexHandle->SearchRange(tmpvec, left, right, SMALLER, 0);
    printf("Result length: %d\n", tmpvec.size());
    rmg->closeFile(*handler);
}

void test1(){
    RM_Manager *rmg = new RM_Manager("test");
    RM_FileHandle *handler = new RM_FileHandle();
    rmg->createFile("helloworld1", 500);
    string test = rmg->openFile("helloworld1", *handler) ? "successfully opened" : "fail to open";
    BufType buf = new uint[500];
    for(int i = 0;i < 500;i++)
    	buf[i] = i;
    BufType upBuf = new uint[500];
    for (int i = 0; i < 500; i++)
    	upBuf[i] = 0;
    RM_Record pData;
	RID insertId(1, 0);//useless
	RID deleteId(1, 0);
	RID queryId(1, 1);
	RID upId(1, 1);
	RM_Record rec;
	RM_Record upRec;
	upRec.SetRecord(upBuf,500, upId);
    pData.SetRecord(buf,500,insertId);
    handler->InsertRec(pData);
	handler->InsertRec(pData);
	handler->InsertRec(pData);
	handler->InsertRec(pData);
	handler->DeleteRec(deleteId);
	handler->InsertRec(pData);
	handler->InsertRec(pData);
	handler->UpdateRec(upRec);
	handler->GetRec(queryId, rec);
	BufType recBuf = rec.GetData();
	rmg->closeFile(*handler);
}
*/

void testBitmap() {
	
	MyBitMap *b = new MyBitMap(2 << 5, 2);
	b->show();
	cout << "left"<<b->findLeftOne() << endl;
	b->setBit(33, 1);
	cout << "left" << b->findLeftOne() << endl;
	//b->setBit(3, 1);
	b->show();
}



int main(){
#ifdef __DARWIN_UNIX03
    printf("It is on Unix now.\n");
#endif
    MyBitMap::initConst();
    // test1();
    NewTest();
    return 0;
}