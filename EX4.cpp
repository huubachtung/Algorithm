#include <iostream>
#include <string>
#include <sstream>  // for std::istringstream

using namespace std;

int main() {

    // Declare arrays to store data
    string customerID[100];
    string productID[100];
    int price[100];
    string shopID[100];
    string timePoint[100];

    int orderCount = 0;

    // Read the number of orders
    cout << "Enter the number of orders: ";
    cin >> orderCount;
    cin.ignore(); // Ignore the newline character

    for(int index=0;index<orderCount;index++) {
        // Extract words from the string stream
        string aLine;
        cout<<"Hay nhap thong tin don hang thu "<<index+1<<": ";
        getline(cin,aLine);
        istringstream stream(aLine);
        stream >> customerID[index];
        stream >> productID[index];
        stream >> price[index];
        stream >> shopID[index];
        stream >> timePoint[index];

        if(customerID[index].length()>10||customerID[index].length()<3) {
            cout<<"The customer ID is too long.Enter the customer ID (length from 3 to 10). Please try again."<<endl;
            index--;
            continue;
        }
        if(productID[index].length()>10||productID[index].length()<3) {
            cout<<"The product ID is too long.Enter the product ID (string of length from 3 to 10). Please try again."<<endl;
            index--;
            continue;
        }
        if(price[index]>1000||price[index]<1) {
            cout<<"The price is out of range.It is just between 1 to 1000. Please try again."<<endl;
            index--;
            continue;
        }
        if(shopID[index].length()>10||shopID[index].length()<3) {
            cout<<"The shop ID is too long. Enter the shop ID (length from 3 to 10). Please try again."<<endl;
            index--;
            continue;
        }
        if(timePoint[index].length()!=8||timePoint[index][2]!=':'||timePoint[index][5]!=':') {
            cout<<"Invalid format. Enter the time point (HH:MM:SS . For example 10:30:10). Please try again"<<endl;
            index--;
            continue;
        }else if(timePoint[index][0]<'0'||timePoint[index][0]>'2'||timePoint[index][1]<'0'||timePoint[index][1]>'9'||
                 timePoint[index][3]<'0'||timePoint[index][3]>'5'||timePoint[index][6]<'0'||timePoint[index][6]>'5'||
                 timePoint[index][7]<'0'||timePoint[index][7]>'9') {
            cout<<"Invalid time point. Enter the time point (HH:MM:SS . For example 10:30:10). Please try again."<<endl;
            index--;
            continue;
        }else if(timePoint[index][0]=='2'&&timePoint[index][1]>='4') {
            cout<<"Invalid time point. Not longer than 23:59:59. Please try again."<<endl;
            index--;
            continue;
        }
    }

    // Task 1: Sort orders by time in descending order
    for (int i = 0; i < orderCount - 1; ++i) {
        for (int j = i + 1; j < orderCount; ++j) {
            if (timePoint[i] < timePoint[j]) {
                // Swap all fields for the two orders
                string temp;

                // Swap customerID
                temp = customerID[i];
                customerID[i] = customerID[j];
                customerID[j] = temp;

                // Swap productID
                temp = productID[i];
                productID[i] = productID[j];
                productID[j] = temp;

                // Swap price
                int tempPrice = price[i];
                price[i] = price[j];
                price[j] = tempPrice;

                // Swap shopID
                temp = shopID[i];
                shopID[i] = shopID[j];
                shopID[j] = temp;

                // Swap timePoint
                temp = timePoint[i];
                timePoint[i] = timePoint[j];
                timePoint[j] = temp;
            }
        }
    }

    cout << "\nSorted Orders by Time (Descending):\n";
    for (int i = 0; i < orderCount; ++i)
        cout << customerID[i] << " " << productID[i] << " "<< price[i] << " " << shopID[i] << " " << timePoint[i] <<endl;


    // Task 2: Find the best-selling product and shop
    int maxCount = 0;
    string bestProductID="";
    for (int i = 0; i < orderCount; ++i) {
        int count = 0;
        for (int j = 0; j < orderCount; ++j) {
            if (productID[i] == productID[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            bestProductID = productID[i];
        }
    }

    // Find shop has the highest sales for the best product
    int maxPrice = 0;
    int previousBestShop =0;
    string bestShopID="";
    int soldQuantity=0;

    for (int i = 0; i < orderCount; ++i) {
        if (productID[i] == bestProductID) {
            soldQuantity++;

            int priceEach = 0;
            for (int j = 0; j < orderCount; ++j) {
                if (shopID[i] == shopID[j]) {
                    priceEach += price[j];
                }
            }
            if(priceEach==maxPrice) {
                for(int k=0;k<orderCount;k++) {
                    int priceTemp1=0;
                    int priceTemp2=0;
                    if(shopID[previousBestShop]==shopID[k]) {
                        priceTemp1+=price[k];
                    }
                    if(shopID[i]==shopID[k]) {
                        priceTemp2+=price[k];
                    }
                    if(priceTemp1<priceTemp2) {
                        bestShopID = shopID[i];
                        previousBestShop=i;
                    }
                }
                }

                if (priceEach > maxPrice) {
                    maxPrice = priceEach;
                    bestShopID = shopID[i];
                    previousBestShop=i;
                }
            }
        }
        cout << "\nBest-selling Product ID: " << bestProductID
             << "\nNumber of products sold: " << soldQuantity
             << "\nShop with highest total for that product: " << bestShopID <<endl;

        // Task 3: Find the loyal customer
        int maxSpent = 0;
        string loyalCustomerID;
        for (int i = 0; i < orderCount; ++i) {
            int totalSpent = 0;
            for (int j = 0; j < orderCount; ++j) {
                if (customerID[i] == customerID[j]) {
                    totalSpent += price[j];
                }
            }
            if (totalSpent > maxSpent) {
                maxSpent = totalSpent;
                loyalCustomerID = customerID[i];
            }
        }

        cout << "\nLoyal Customer (most purchases): " << loyalCustomerID <<endl;
    return 0;
}
