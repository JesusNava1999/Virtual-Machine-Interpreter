#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <cstdlib>

#include "VM_Interpreter.h"
#include "Virtual_Machine.h"

using namespace std;

int main(){
    string name = "";
    string type = "";
    int cpus = 0;
    int ram = 0;
    int vram = 0;
    int diskmem = 0;
    string natName = "";

    system("clear");
    cout << "WELCOME TO VIRTUAL MACHINE MAKER" << endl;
    cout << "Type a name for your Virtual Machine (Ubuntu1): ";
    cin >> name;
    /*
    cout << "Type a OStype for your Virtual Machine: ";
    cin >> type;
    cout << "Type the number of CPU's for your Virtual Machine: ";
    cin >> cpus;
    cout << "Type the RAM Memory (MB) for your Virtual Machine: ";
    cin >> ram;
    cout << "Type the Video Memory (MB) for your Virtual Machine: ";
    cin >> vram;
    cout << "Type the Disk Memory (Storage)-(MB) for your Virtual Machine: ";
    cin >> diskmem;
    */
    cout << "Type NatNetwork Name: (NATNetwork101): ";
    cin >> natName;
    
    VM_Interpreter vm_m1(name,type,cpus,ram,vram,diskmem,natName);
    Virtual_Machine vm1(name,type,cpus,ram,vram,diskmem, natName);
    system("clear");
    /*cout << "Creating the Virtual Machine..." << endl;
    sleep(2);
    vm_m1.createVM();
    system("clear");
    cout << "Attaching CPU's, RAM and VRAM..." << endl;
    sleep(2);    
    vm_m1.addCpusRamVram();
    system("clear");
    cout << "Attaching Network Adapter..." << endl;
    sleep(2);    
    vm_m1.addNetAdap();
    system("clear");
    cout << "Creating Disk Memory (storage)..." << endl;
    sleep(2);    
    vm_m1.createDiskMem();
    system("clear");
    cout << "Attaching SATA Controller..." << endl;
    sleep(2);    
    vm_m1.addController();
    system("clear");
    cout << "Attaching Disk Memory (storage)..." << endl;
    sleep(2);    
    vm_m1.addDiskMem();
    system("clear");
    cout << "Attaching IDE Controller..." << endl;
    sleep(2);  
    system("clear");
    cout << "Adding IDE Content..." << endl; 
    vm_m1.addIdeCont(); 
    sleep(2);   
    system("clear");
    cout << "Finishing..." << endl; 
    sleep(2); 
    cout << "DONE :)" << endl;*/
    ///////////////////////////////////////////////////////////////////
    cout << "Listing NAT Networks..." << endl;
    vm_m1.listNatNetworks();
    sleep(2); 
    system("clear");
    cout << "Creating a new NAT Network..." << endl;
    vm_m1.createNatNetwork();
    sleep(2); 
    system("clear");
    cout << "Enabling DHCP..." << endl;
    vm_m1.enableDHCP();
    sleep(2); 
    system("clear");
    /*cout << "Disabling DHCP..." << endl;
    vm_m1.disableDHCP();
    sleep(2); 
    system("clear");*/    
    cout << "Starting NAT Service..." << endl;
    vm_m1.startNATService();
    sleep(2); 
    system("clear");
    cout << "Enabling Port Fowarding..." << endl;
    vm_m1.enablePortFowarding();
    sleep(2); 
    system("clear");    
    cout << "Linking NAT Network..." << endl;
    vm_m1.linkNATNetwork();
    sleep(2); 
    system("clear");
    /*cout << "Deleting NAT Network..." << endl;
    vm_m1.deleteNATNetwork();
    sleep(2); 
    system("clear");*/
    cout << "Finishing..." << endl; 
    sleep(2); 
    cout << "DONE :)" << endl;
    return 0;
}