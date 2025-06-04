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
        QMessageBox::information(nullptr, "Bilgi", "Esya eklenmistir.\n");
    }

    void findItem(const QString& itemName) {
        for (const auto& item : inventory) {
            if (item.name == itemName) {
                QMessageBox::information(nullptr, "Bilgi", "Esya bulundu:\n" +
                                                               item.name + " - Konum: " + item.location);
                return;
            }
        }
        QMessageBox::warning(nullptr, "Uyarı", "Esya bulunamadı.");
    }

    void listInventory() {
        if (inventory.isEmpty()) {
            QMessageBox::information(nullptr, "Bilgi", "Envanter bos.\n");
            return;
        }

        QString inventoryText = "Envanter:\n";
        for (const auto& item : inventory) {
            inventoryText += " - " + item.name + " - Konum: " + item.location + "\n";
        }
        QMessageBox::information(nullptr, "Envanter", inventoryText);
    }
};

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    InventoryManager inventoryManager;

    while (true) {
        int choice = QInputDialog::getInt(nullptr, "Secenek", "Secenek:", 1, 1, 5, 1);

        if (choice == 1) {
            QString itemName = QInputDialog::getText(nullptr, "Esya Ekle", "Esya Adi veya Takip No:");
            QString itemLocation = QInputDialog::getText(nullptr, "Esya Ekle", "Konum:");
            inventoryManager.addItem(itemName, itemLocation);
        }
        else if (choice == 2) {
            QString itemName = QInputDialog::getText(nullptr, "Esya Bul", "Aranacak Esya Adi veya Takip No:");
            inventoryManager.findItem(itemName);
        }
        else if (choice == 3) {
            inventoryManager.listInventory();
        }
        else if (choice == 4) {
            break;
        }
        else if (choice == 5) {
            QMessageBox::information(nullptr, "Bilgi", "Uygulama kapatılıyor.");
            return 0; // Uygulamayı kapat
        }
        else {
            QMessageBox::warning(nullptr, "Hata", "Gecersiz secenek. Tekrar deneyin.");
        }
    }

    return a.exec();
}
