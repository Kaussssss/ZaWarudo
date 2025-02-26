#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    std::string productName;
    int productID;
    double pricePerUnit;
    int availableStock;
    std::string supplierName;

public:
    Product(std::string name, int id, double price, int stock, string supplier) {
        productName = name;
        productID = id;
        pricePerUnit = price;
        availableStock = stock;
        supplierName = supplier;
    }

    void displayProductDetails() {
        cout << "Product ID: " << productID << "\n";
        cout << "Product Name: " << productName << "\n";
        cout << "Price per Unit: $" << pricePerUnit << "\n";
        cout << "Available Stock: " << availableStock << "\n";
        cout << "Supplier: " << supplierName << "\n\n";
    }

    double getTotalValue() {
        return pricePerUnit * availableStock;
    }

    bool isStockLow() {
        return availableStock < 10;
    }

    string getProductName() {
        return productName;
    }
};

double calculateTotalInventoryValue(vector<Product> &inventory) {
    double totalValue = 0;
    for (Product &product : inventory) {
        totalValue += product.getTotalValue();
    }
    return totalValue;
}

void displayLowStockProducts(vector<Product> &inventory) {
    cout << "\nProducts that need restocking:\n";
    bool found = false;
    for (Product &product : inventory) {
        if (product.isStockLow()) {
            cout << product.getProductName() << " (Stock: " << product.getTotalValue() / product.getTotalValue() << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "All products have sufficient stock.\n";
    }
}

int main() {
    vector<Product> inventory = {
        Product("Laptop", 101, 750.99, 15, "TechSupplier Inc."),
        Product("Mouse", 102, 25.50, 5, "Gadgets Corp."),
        Product("Keyboard", 103, 45.75, 8, "KeyTech Ltd."),
        Product("Monitor", 104, 200.00, 20, "DisplayWorld"),
        Product("USB Drive", 105, 15.99, 3, "Storage Solutions")
    };

    cout << "Product Details:\n";
    for (Product &product : inventory) {
        product.displayProductDetails();
    }

    cout << "Total Inventory Value: $" << calculateTotalInventoryValue(inventory) << "\n";

    displayLowStockProducts(inventory);

    return 0;
}
