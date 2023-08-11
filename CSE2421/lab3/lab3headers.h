/*Naishal Patel*/

#define MAX_NAME_LENGTH 64
#define MAX_CONTENT_LENGTH 256
#define MAX_CHILDREN 64

struct File{
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
};

struct Directory {
    char name[MAX_NAME_LENGTH];
    struct Directory *parent;
    struct File *files[MAX_CHILDREN];
    struct Directory *subdirectories[MAX_CHILDREN];
    int fileCount;
    int directoryCount;
};

int processCmd(struct Directory *currentDirectory);

void cat(struct Directory *currentDirectory, const char *filename);
struct Directory *cd(struct Directory *currentDirectory, const char *directoryName);
void cp(struct Directory *currentDirectory, const char *source, const char *destinationPath);
void help();
void ls(struct Directory *directory);
struct Directory *mkdir(const char *name,struct Directory *parent);
void mv(struct Directory *currentDirectory,const char *sourcePath, const char *destinationPath);
void pwd(struct Directory *currentDirectory);
void rm(struct Directory *directory,struct File *file);
void rmdir(struct Directory *currentDirectory,struct Directory *directoryToRemove);
void dirprint(struct Directory *currentDirectory);
void search(struct Directory *currentDirectory, const char *searchTerm);
void fedit(struct Directory *currentDirectory, const char *fileName);
void blank(struct Directory *currentDirectory, const char *fileName);
struct File *mkfile(const char *fileName);

struct File *file(const char *fileName, const char *content);
struct File *findFile(struct Directory *directory, const char *fileName);
struct Directory *findDirectory(struct Directory* currentDirectory, const char* directoryName);
void addFileToDirectory(struct Directory *directory,struct File *file);
void addDirectoryToDirectory(struct Directory *directory,struct Directory *subdirectory);
void copyDirectoryContents(struct Directory *sourceDirectory,struct Directory *destinationDirectory);
void freeDirectory(struct Directory *directory);

