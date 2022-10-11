#ifndef Virtual_Machine_h
#define Virtual_Machine_h

#include <stddef.h>
#include <string.h>
#include <iostream>

using namespace std;

class Virtual_Machine{
    string vBoxManage;
    string vm_name;
    string os_type;
    int cpus;
    int ram_memory;
    int v_ram;
    int disk_memory;
    string natNetworkName;
public:
    Virtual_Machine(string, string, int, int, int, int, string);
    
    void getVm_name();
    void getOs_type();
    void getCpus();
    void getRam_memory();
    void getV_ram();
    void showVmInfo();
};

#endif // !Virtual_Machine_h
