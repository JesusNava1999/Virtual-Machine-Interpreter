#include <iostream>
#include <string>

#include "VM_Interpreter.h"

using namespace std;

VM_Interpreter::VM_Interpreter(string _vm_name, string _os_type, int _cpus, int _ram_memory, int _v_ram, int _disk_memory, string _natNetworkName){
    vBoxManage = "VBoxManage";
    vm_name = _vm_name;
    os_type = _os_type;
    cpus = _cpus;
    ram_memory = _ram_memory;
    v_ram = _v_ram;
    disk_memory = _disk_memory;
    natNetworkName = _natNetworkName;
}

void VM_Interpreter::createVM(){
    string aux = vBoxManage + " createvm --name " + vm_name + " --ostype " + os_type + " --register";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::addCpusRamVram() {
    string aux = vBoxManage + " modifyvm " + vm_name + " --cpus " + to_string(cpus) + " --memory " + to_string(ram_memory) + " --vram " + to_string(v_ram);
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::addNetAdap() {
    string aux = vBoxManage + " modifyvm " + vm_name + " --nic1 NAT";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::createDiskMem() {
    string aux = vBoxManage + " createhd --filename ~/VirtualBox\\ VMs/UbuntOSX --size " + to_string(disk_memory);
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::addController() {
    string aux = vBoxManage + " storagectl " + vm_name + " --name 'SATA Controller' --add sata --bootable on";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);    
}

void VM_Interpreter::addDiskMem() {
    string aux = vBoxManage + " storageattach " + vm_name + " --storagectl 'SATA Controller' --port 0 --device 00 --type hdd --medium ~/VirtualBox\\ VMs/UbuntOSX.vdi";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);    
}

void VM_Interpreter::addIdeCont() {  
    string aux = vBoxManage + " storagectl " + vm_name + " --storagectl 'IDE Controller' --add ide";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);

    string aux2 = vBoxManage + " storageattach " + vm_name + " --storagectl 'IDE Controller' --port 0 --device 0 --type dvddrive --medium /home/navarq/Downloads/ubuntu-20.04.4-desktop-amd64.iso";
    char* cmd2;
    cmd2 = new char[aux2.length()];
    for (int i = 0; i < aux2.length(); i++) {
        cmd2[i] = aux2[i];
    }    
    // cout << cmd2 << endl;
    system(cmd2);
}

void VM_Interpreter::listNatNetworks(){
    string aux = vBoxManage + " list natnetworks";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd); 
}

void VM_Interpreter::createNatNetwork(){
    string aux = vBoxManage + " natnetwork add --netname " + natNetworkName + " --network '192.168.10.0/24' --enable";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::enableDHCP(){
    string aux = vBoxManage + " natnetwork modify --netname " + natNetworkName + " --dhcp on";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::disableDHCP(){
    string aux = vBoxManage + " natnetwork modify --netname " + natNetworkName + " --dhcp off";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::startNATService(){
    string aux = vBoxManage + " natnetwork start --netname " + natNetworkName;
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::enablePortFowarding(){
    string aux = vBoxManage + " natnetwork modify --netname " + natNetworkName + " \\--port-forward-4 ssh:tcp:[10.0.2.15]:2222:[192.168.10.4]:22";
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::linkNATNetwork(){
    string aux = vBoxManage + " modifyvm " + vm_name + " --nic1 natnetwork --nat-network1 " + natNetworkName; 
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}

void VM_Interpreter::deleteNATNetwork(){
    string aux = vBoxManage + " natnetwork remove --netname " + natNetworkName;
    char* cmd;
    cmd = new char[aux.length()];
    for (int i = 0; i < aux.length(); i++) {
        cmd[i] = aux[i];
    }    
    // cout << cmd << endl;
    system(cmd);
}