#include"AssetManagementSystem.hpp"

AssetManagementSystem* AssetManagementSystem::instance = nullptr;

AssetManagementSystem* AssetManagementSystem::getInstance(){
    if(instance == nullptr){
        instance = new AssetManagementSystem;
    }

    return instance;
}

void AssetManagementSystem::registerEmployee(Employee* employee){
    employees[employee->getId()] = employee;
}

void AssetManagementSystem::registerDevice(Device* device){
    devices[device->getId()] = device;
}

void AssetManagementSystem::registerSoftware(Software* software){
    softwares[software->getName()] = software;
}

void AssetManagementSystem::registerVendors(Vendor* vendor){
    vendors[vendor->getName()] = vendor;
}

void AssetManagementSystem::particularSoftwareInstallation(string softwareName){
    auto it = softwares.find(softwareName);
    if(it != softwares.end()){
        Software* software = it->second;
        int totalInstallationNo = software->getInstallation();
        cout<<totalInstallationNo;
        return;
    }
    cout<<"The Software isnt available in our database!"<<'\n';
}

void AssetManagementSystem::noOfSoftwareInstalledInDevice(int deviceId){
    auto it = devices.find(deviceId);
    if(it != devices.end()){
        Device* device = it->second;
        int totalInstallation = device->getTotalSoftwareInstalled();
        cout<<totalInstallation;
        return;
    }
    
    cout<<"The deviceId: "<<deviceId<<" isnt available in our database"<<'\n';
}

void AssetManagementSystem::noOfSoftwareInstalledInEmployee(int employeeId){
    auto it = employees.find(employeeId);
    if(it != employees.end()){
        Employee* employee = it->second;
        int totalInstallation = employee->calculateNoOfSoftware();
        cout<<"No of software installed for the employee: "<<employee->getName()<<" "<<totalInstallation;
        return;
    }

    cout<<"EmployeeId: "<<employeeId<<" isnt in our database"<<'\n';
}

void AssetManagementSystem::amountSpendForaSoftware(string softwareName){
    auto it = softwares.find(softwareName);
    if(it != softwares.end()){
        Software* software = it->second;
        int amountSpent = software->getAmountSpent();
        cout<<"Amount Spent for the Software: "<<softwareName<<" is: "<<amountSpent<<'\n';
        return;
    }
    cout<<"The requested software isnt in our database"<<'\n';
}

void AssetManagementSystem::amountSpentForEmployee(int employeeId) {
    auto it = employees.find(employeeId);
    if(it != employees.end()) {
        Employee* employee = it->second;
        int totalAmount = employee->calculateAmountSpent();
        cout << "Amount spent for employee: " << employee->getName() << " is " << totalAmount << '\n';
        return;
    }
    cout << "EmployeeId: " << employeeId << " is not in our database" << '\n';
}

void AssetManagementSystem::devicesWithExpiredSoftware(const string& currentDate) {
    for (auto& it : devices) {
        Device* device = it.second;
        if (device->hasExpiredSoftware(currentDate)) {
            cout << "Device ID: " << device->getId() << " has expired software.\n";
        }
    }
}

void AssetManagementSystem::amountSpentForVendor(string vendorName){
    auto it = vendors.find(vendorName);
    if(it != vendors.end()){
        Vendor* vendor = it->second;
        int totalAmount = vendor->getAmountSpent();
        cout<<"Amount spent on a vendor: "<<vendorName<<" is: "<<totalAmount;
        return;
    }
    cout<<"The Vendor isnt in our database"<<'\n';
}

void AssetManagementSystem::noOfInstalledSoftwareFromVendor(string vendorName){
    auto it = vendors.find(vendorName);
    if(it != vendors.end()){
        Vendor* vendor = it->second;
        int totalSoftwareInstalled = vendor->getSoftwareInstallation();
        cout<<"No of Installatins of software from the vendor: "<<vendorName<<" is: "<<totalSoftwareInstalled;
        return;
    }
    cout<<"The vendor you have requested isnt in our database"<<'\n';
}
