#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMap>
#include <QDateEdit>

struct CargoInfo {
    QString name;
    QString trackingNumber;
    QString location;
    QString type;
};

class CargoTrackingSystem : public QWidget {
    Q_OBJECT

public:
    CargoTrackingSystem(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Kargo Takip Sistemi");

        // Kargo Takip Girişi
        QLabel *nameLabel = new QLabel("Ad Soyad:", this);
        nameLineEdit = new QLineEdit(this);

        QLabel *trackingLabel = new QLabel("Kargo Takip Numarası:", this);
        trackingLineEdit = new QLineEdit(this);

        QLabel *locationLabel = new QLabel("Kargo Lokasyonu:", this);
        locationLineEdit = new QLineEdit(this);

        QLabel *typeLabel = new QLabel("Kargo Türü:", this);
        typeLineEdit = new QLineEdit(this);

        QLabel *dateLabel = new QLabel("Tarih:", this);
        dateEdit = new QDateEdit(QDate::currentDate(), this);

        QPushButton *trackButton = new QPushButton("Takip Et", this);
        QPushButton *cancelButton = new QPushButton("İptal Et", this);

        // Sonuç Gösterimi
        resultTextEdit = new QTextEdit(this);
        resultTextEdit->setReadOnly(true);

        // Layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        mainLayout->addWidget(nameLabel);
        mainLayout->addWidget(nameLineEdit);

        mainLayout->addWidget(trackingLabel);
        mainLayout->addWidget(trackingLineEdit);

        mainLayout->addWidget(locationLabel);
        mainLayout->addWidget(locationLineEdit);

        mainLayout->addWidget(typeLabel);
        mainLayout->addWidget(typeLineEdit);

        mainLayout->addWidget(dateLabel);
        mainLayout->addWidget(dateEdit);

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(trackButton);
        buttonLayout->addWidget(cancelButton);

        mainLayout->addLayout(buttonLayout);
        mainLayout->addWidget(resultTextEdit);

        setLayout(mainLayout);

        // Signal-Slot bağlantıları
        connect(trackButton, &QPushButton::clicked, this, &CargoTrackingSystem::trackCargo);
        connect(cancelButton, &QPushButton::clicked, this, &CargoTrackingSystem::cancelCargo);
    }

private slots:
    void trackCargo() {
        if (!validateInput()) {
            return;
        }

        // Kargo bilgilerini al
        CargoInfo cargo;
        cargo.name = nameLineEdit->text();
        cargo.trackingNumber = trackingLineEdit->text();
        cargo.location = locationLineEdit->text();
        cargo.type = typeLineEdit->text();
        QString date = dateEdit->date().toString("dd.MM.yyyy");

        // Gerçek bir kargo takip sistemi burada olacak
        // Bu örnek sadece bilgileri ekrana yazdırıyor
        QString result = "Ad Soyad: " + cargo.name + "\n"
                                                     "Kargo Takip Numarası: " + cargo.trackingNumber + "\n"
                                                  "Lokasyon: " + cargo.location + "\n"
                                            "Kargo Türü: " + cargo.type + "\n"
                                        "Tarih: " + date;

        // Sonucu göster
        resultTextEdit->setPlainText(result);
    }

    void cancelCargo() {
        // Kargo iptal işlemleri
        resultTextEdit->clear();
    }

private:
    QLineEdit *nameLineEdit;
    QLineEdit *trackingLineEdit;
    QLineEdit *locationLineEdit;
    QLineEdit *typeLineEdit;
    QTextEdit *resultTextEdit;
    QDateEdit *dateEdit;

    bool validateInput() {
        // Gerekli alanların boş olup olmadığını kontrol et
        if (nameLineEdit->text().isEmpty() || trackingLineEdit->text().isEmpty() ||
            locationLineEdit->text().isEmpty() || typeLineEdit->text().isEmpty()) {
            // Gerekli alanlar boşsa kullanıcıya uyarı gösterilebilir
            return false;
        }
        return true;
    }
};

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    CargoTrackingSystem cargoTrackingSystem;
    cargoTrackingSystem.show();

    return app.exec();
}

#include "main.moc"
