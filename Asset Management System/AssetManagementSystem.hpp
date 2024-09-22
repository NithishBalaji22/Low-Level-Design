#pragma once
#include"Device.hpp"
#include"Employee.hpp"
#include"Installation.hpp"
#include"Software.hpp"
#include"Vendor.hpp"
#include<bits/stdc++.h>
using namespace std;

class AssetManagementSystem{
    private:
        static AssetManagementSystem* instance;
        unordered_map<int, Employee*> employees;
        unordered_map<int, Device*> devices;
        unordered_map<string, Software*> softwares;
        unordered_map<string, Vendor*> vendors;
        AssetManagementSystem(){
            employees = unordered_map<int, Employee*>();
            devices = unordered_map<int, Device*>();
            softwares = unordered_map<string, Software*>();
            vendors = unordered_map<string, Vendor*>();
        }

    public:
        static AssetManagementSystem* getInstance ();
        void registerEmployee(Employee* employee);
        void registerDevice(Device* device);
        void registerSoftware(Software* software);
        void registerVendors(Vendor* vendor);
        void particularSoftwareInstallation(string softwareName);
        void noOfSoftwareInstalledInDevice(int deviceId);
        void devicesWithExpiredSoftware(const string& currentDate);
        void noOfSoftwareInstalledInEmployee(int employeeId);
        void amountSpendForaSoftware(string softwareName);
        void amountSpentForVendor(string vendorName);
        void amountSpentForEmployee(int employeeId);
        void noOfInstalledSoftwareFromVendor(string vendorName);
};