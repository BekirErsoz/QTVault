#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include <QString>
#include <QVector>

struct Item {
    QString name;
    QString location;
};

class InventoryManager {
private:
    QVector<Item> inventory;

public:
    void addItem(const QString& itemName, const QString& itemLocation) {
        Item newItem;
        newItem.name = itemName;
        newItem.location = itemLocation;
        inventory.push_back(newItem);
        QMessageBox::information(nullptr, "Bilgi", "Kargo eklenmiştir.");
    }

    void findItem(const QString& itemName) {
        for (const auto& item : inventory) {
            if (item.name == itemName) {
                QMessageBox::information(nullptr, "Bilgi", "Kargo bulundu: " + item.name + " - Konum: " + item.location);
                return;
            }
        }
        QMessageBox::warning(nullptr, "Uyarı", "Kargo bulunamadı.");
    }

    void listInventory() {
        if (inventory.empty()) {
            QMessageBox::information(nullptr, "Bilgi", "Envanter boş.");
            return;
        }

        QString inventoryList = "Envanter:\n";
        for (const auto& item : inventory) {
            inventoryList += " - " + item.name + " - Konum: " + item.location + "\n";
        }

        QMessageBox::information(nullptr, "Envanter", inventoryList);
    }
};

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);
    InventoryManager inventoryManager;

    while (true) {
        QStringList choices;
        choices << "Kargo Ekle" << "Kargo Bul" << "Kargoları Listele" << "Çıkış";

        QString choice = QInputDialog::getItem(nullptr, "Seçenek", "Seçenek:", choices, 0, false);

        if (choice == "Çıkış" || choice.isEmpty()) {
            break;
        }

        if (choice == "Kargo Ekle") {
            QString itemName = QInputDialog::getText(nullptr, "Kargo Ekle", "Kargo Adı veya Takip No:");
            if (itemName.isEmpty()) {
                break;
            }

            QString itemLocation = QInputDialog::getText(nullptr, "Kargo Ekle", "Konum:");
            if (itemLocation.isEmpty()) {
                break;
            }

            inventoryManager.addItem(itemName, itemLocation);
        }
        else if (choice == "Kargo Bul") {
            QString itemName = QInputDialog::getText(nullptr, "Kargo Bul", "Aranacak Kargo Adı veya Takip No:");
            if (itemName.isEmpty()) {
                break;
            }

            inventoryManager.findItem(itemName);
        }
        else if (choice == "Kargoları Listele") {
            inventoryManager.listInventory();
        }
        else {
            QMessageBox::critical(nullptr, "Hata", "Geçersiz seçenek. Tekrar deneyiniz.");
        }
    }

    return 0;
}
