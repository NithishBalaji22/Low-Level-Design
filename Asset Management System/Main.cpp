#include "AssetManagementSystem.hpp"
#include "Employee.hpp"
#include "Device.hpp"
#include "Software.hpp"
#include "Vendor.hpp"
#include "Installation.hpp"
#include <iostream>

using namespace std;

int main() {
    // Create the Asset Management System instance
    AssetManagementSystem* assetSystem = AssetManagementSystem::getInstance();

    // Register Vendors
    Vendor* vendor1 = new Vendor(1, "VendorA");
    Vendor* vendor2 = new Vendor(2, "VendorB");
    assetSystem->registerVendors(vendor1);
    assetSystem->registerVendors(vendor2);

    // Register Software
    Software* software1 = new Software(1, "SoftwareA", 500, 2);
    Software* software2 = new Software(2, "SoftwareB", 300, 1);
    assetSystem->registerSoftware(software1);
    assetSystem->registerSoftware(software2);
    
    // Add software to vendors
    vendor1->addSoftware(software1);
    vendor2->addSoftware(software2);

    // Register Employees
    Employee* emp1 = new Employee(1, "John Doe");
    Employee* emp2 = new Employee(2, "Jane Smith");
    assetSystem->registerEmployee(emp1);
    assetSystem->registerEmployee(emp2);

    // Register Devices
    Device* device1 = new Device(1, "Device1");
    Device* device2 = new Device(2, "Device2");
    assetSystem->registerDevice(device1);
    assetSystem->registerDevice(device2);

    // Assign devices to employees
    emp1->addDevice(device1);
    emp2->addDevice(device2);

    // Create Installations
    Installation* inst1 = new Installation(1, software1, "2022-01-01", "2023-01-01"); // Expired
    Installation* inst2 = new Installation(2, software2, "2023-05-01", "2024-05-01"); // Not expired

    // Add installations to devices
    device1->addInstallation(inst1);
    device2->addInstallation(inst2);

    // Test Outputs
    cout << "1. No. of installations of a particular software (SoftwareA):\n";
    assetSystem->particularSoftwareInstallation("SoftwareA");
    cout << "\n\n";

    cout << "2. No. of software installed in a device (Device1):\n";
    assetSystem->noOfSoftwareInstalledInDevice(1);
    cout << "\n\n";

    cout << "3. No. of software installed for an employee (John Doe):\n";
    assetSystem->noOfSoftwareInstalledInEmployee(1);
    cout << "\n\n";

    cout << "4. Amount spent for a software (SoftwareA):\n";
    assetSystem->amountSpendForaSoftware("SoftwareA");
    cout << "\n\n";

    cout << "5. Amount spent on a vendor (VendorA):\n";
    assetSystem->amountSpentForVendor("VendorA");
    cout << "\n\n";

    cout << "6. No. of installations of software from a vendor (VendorA):\n";
    assetSystem->noOfInstalledSoftwareFromVendor("VendorA");
    cout << "\n\n";

    cout << "7. Devices with expired software:\n";
    assetSystem->devicesWithExpiredSoftware("2023-12-01"); // Checking for expired software as of 2023-12-01
    cout << "\n\n";

    // 8. Amount spent for an employee
    cout << "8. Amount spent for an employee (John Doe):\n";
    assetSystem->amountSpentForEmployee(1);
    cout << "\n\n";

    return 0;
}
