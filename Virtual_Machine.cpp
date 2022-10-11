#include "Virtual_Machine.h"

using namespace std;

Virtual_Machine::Virtual_Machine(string _vm_name, string _os_type, int _cpus, int _ram_memory, int _v_ram, int _disk_memory, string _natNetworkName){
    vBoxManage = "VBoxManage";
    vm_name = _vm_name;
    os_type = _os_type;
    cpus = _cpus;
    ram_memory = _ram_memory;
    v_ram = _v_ram;
    disk_memory = _disk_memory;
    natNetworkName = _natNetworkName;
}

void Virtual_Machine::getVm_name(){
    string aux = vBoxManage + " showvminfo " + vm_name + " | grep Name";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);    
}

void Virtual_Machine::getOs_type(){
    string aux = vBoxManage + " showvminfo " + vm_name + " | grep 'Guest OS'";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd); 
}

void Virtual_Machine::getCpus(){
    string aux = vBoxManage + " showvminfo " + vm_name + " | grep CPUs";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd); 
}

void Virtual_Machine::getRam_memory(){
    string aux = vBoxManage + " showvminfo " + vm_name + " | grep Memory";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd); 
}

void Virtual_Machine::getV_ram(){
    string aux = vBoxManage + " showvminfo " + vm_name + " | grep VRAM";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd); 
}

void Virtual_Machine::showVmInfo(){
    string aux = vBoxManage + " showvminfo " + vm_name;
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}