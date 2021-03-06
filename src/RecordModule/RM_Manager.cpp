#include "RecordModule/RM_Manager.h"
#include <iostream>
using namespace std;
RM_Manager::RM_Manager(char *dbName) {
    //从cmake-build-debug算起
    dataPath = new char[100];
    char path[50] = "../database/";
    strcat(path, dbName);
    strcat(path, "/");
    strcpy(this->dataPath, path);
    this->fileManager = new FileManager();
    this->bufPageManager = new BufPageManager(fileManager);
    this->fileID = -1;
    this->dbName = new char[strlen(dbName)];
    strcpy(this->dbName, dbName);
}

RM_Manager::~RM_Manager()
{
    delete dataPath;
    delete dbName;
}

/*
static int RM_Manager::GetIndex(string tableName, IM::IndexHandle *indexHandler)
{
    auto iter = indexHandlers->find(tableName);
    if(iter == indexHandlers->end()) {
        return 1;
    }
    else{
        indexHandler = iter->second;
    }
    return 0;
}
*/

int RM_Manager::createFile(const char* name, int recordSize, int cNum) {
    FileManager *fm = this->fileManager;
    char fileName[50];
    strcpy(fileName, this->dataPath);
    strcat(fileName, name);
    printf("%s\n", fileName);
    fm->createFile(fileName);
    int fileID;
    fm->openFile(fileName, fileID);
    string tmpStr(fileName);
    tmpStr += "_index/";
    PageHead *test = new PageHead(recordSize, (int)(double(PAGE_INT_NUM - 1) / ((double)recordSize + 1 / 32)), 0, cNum);
    fm->writePage(fileID, 0, test->encode2Buf(), 0);
    fm->closeFile(fileID);
}

bool RM_Manager::openFile(const char* name, RM_FileHandle &fileHandle) {
    char fileName[50];
    char dirSym[10] = "_index/";
    strcpy(fileName, this->dataPath);
    strcat(fileName, name);
    string chartName(name);
    bool result = this->fileManager->openFile(fileName, this->fileID);
    strcat(fileName, dirSym);
    string idx(fileName);
    fileHandle.indexPath = idx;
    RM_FileHandle::CreateDir(idx);
    fileHandle.relatedRManager = new RM_Manager(this->dbName);
    fileHandle.init(this->fileID,this->bufPageManager, chartName);
    return result;
}

int RM_Manager::closeFile(RM_FileHandle &fileHandle) {
    fileHandle.updateHead();
    this->bufPageManager->close();
    return this->fileManager->closeFile(this->fileID);
}

int RM_Manager::deleteFile(const char* name) {
    char fileName[50];
    strcpy(fileName, this->dataPath);
    strcat(fileName, name);
    string rmCommand = "rm ";
    rmCommand += fileName;
    string rmDirCommand = "rm -r ";
    rmDirCommand += fileName;
    rmDirCommand += "_index/";
    system(rmCommand.c_str());
    system(rmDirCommand.c_str());
    printf("Successfully drop the table\n");
    return 0;
}

void RM_Manager::showFile(const char* name) {
    //TODO:show status
    RM_FileHandle *handler = new RM_FileHandle();
    cout<<openFile(name,*handler)<<endl;
    printf("%s\n", name);
    handler->PrintColumnInfo();
    closeFile(*handler);
    //delete handler;
}

void RM_Manager::showAllFile() {
    DIR *dbDir = opendir(this->dataPath);
    if (dbDir == NULL)
    {
        cout << "showAllTABLE " <<  " error" << endl;
        return;
    }
    struct dirent *entry;
    int i = 0;
#ifdef __DARWIN_UNIX03
    struct stat st_buf;
    while (entry = readdir(dbDir))
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, ".." ) != 0) {
            int l = strlen(this->dataPath) + strlen(entry->d_name);
            int cnt = 0;
            char filePath[l];
            memset(filePath, 0, sizeof(filePath));
            strcpy(filePath, this->dataPath);
            strcat(filePath, entry->d_name);
            int status = stat(filePath, &st_buf);
            if (S_ISREG (st_buf.st_mode)) {
                showFile(entry->d_name);
                i++;
            }
        }
    }
#else
    while (entry = readdir(dbDir))
    {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && entry->d_type == 0) {
            showFile(entry->d_name);
            i++;
        }

    }
#endif
    closedir(dbDir);
}