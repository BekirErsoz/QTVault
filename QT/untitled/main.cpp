#include <iostream>
#include <string>
#include <vector>

struct Item {
    std::string name;
    std::string location;
};

class InventoryManager {
private:
    std::vector<Item> inventory;

public:
    void addItem(const std::string& itemName, const std::string& itemLocation) {
        Item newItem;
        newItem.name = itemName;
        newItem.location = itemLocation;
        inventory.push_back(newItem);
        std::cout << "Esya eklenmistir.\n";
    }

    void findItem(const std::string& itemName) {
        for (const auto& item : inventory) {
            if (item.name == itemName) {
                std::cout << "Esya bulundu: " << item.name << " - Konum: " << item.location << "\n";
                return;
            }
        }
        std::cout << "Esya bulunamadi.\n";
    }

    void listInventory() {
        if (inventory.empty()) {
            std::cout << "Envanter boş.\n";
            return;
        }

        std::cout << "Envanter:\n";
        for (const auto& item : inventory) {
            std::cout << " - " << item.name << " - Konum: " << item.location << "\n";
        }
    }
};

int main() {
    InventoryManager inventoryManager;

    while (true) {
        std::cout << "\n1. Esya Ekle\n2. Esya Bul\n3. Envanteri Listele\n4. Cikis\nSecenek: ";

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string itemName, itemLocation;
            std::cout << "Esya Adi: ";
            std::cin >> itemName;
            std::cout << "Konum: ";
            std::cin >> itemLocation;
            inventoryManager.addItem(itemName, itemLocation);
        }
        else if (choice == 2) {
            std::string itemName;
            std::cout << "Aranacak Esya Adi: ";
            std::cin >> itemName;
            inventoryManager.findItem(itemName);
        }
        else if (choice == 3) {
            inventoryManager.listInventory();
        }
        else if (choice == 4) {
            break;
        }
        else {
            std::cout << "Gecersiz secenek. Tekrar deneyin.\n";
        }
    }

    return 0;
}
