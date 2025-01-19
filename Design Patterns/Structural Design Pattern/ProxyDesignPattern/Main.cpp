#include <iostream>
#include "Employer.hpp"
#include "DatabaseInterface.hpp"
#include "DatabaseImpl.hpp"
#include "DatabaseProxy.hpp"
using namespace std;

int main(){
    Employer* nithish = new Employer(2812, "Nithish");
    DatabaseInterface* proxy = new DatabaseProxy();
    proxy->create("ADMIN", nithish);
    proxy->deleteRecord("Client", 2812);
    proxy->get("ADMIN", 2812);
}