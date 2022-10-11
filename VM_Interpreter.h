#ifndef VM_Interpreter_h
#define VM_Interpreter_h

#include <stddef.h>
#include <string>

using namespace std;

class VM_Interpreter{
    string vBoxManage;
    string vm_name;
    string os_type;
    int cpus;
    int ram_memory;
    int v_ram;
    int disk_memory;
    string natNetworkName;

public:
    VM_Interpreter(string, string, int, int, int, int, string);

    void createVM();
    void addCpusRamVram();
    void addNetAdap();
    void createDiskMem();
    void addController();
    void addDiskMem();
    void addIdeCont();
    void listNatNetworks(); 
    void createNatNetwork(); 
    void enableDHCP(); 
    void disableDHCP(); 
    void startNATService(); 
    void enablePortFowarding(); 
    void linkNATNetwork(); 
    void deleteNATNetwork(); 

};

#endif // !VM_Interpreter_h
