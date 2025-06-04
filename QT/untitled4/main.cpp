#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QMap>
#include <QDateTimeEdit>
#include <QComboBox>

struct CargoInfo {
    QString name;
    QString trackingNumber;
    QString location;
    QString type;
    QString staff;
    QDateTime deliveryDateTime;
};

class CargoTrackingSystem : public QWidget {
    Q_OBJECT

public:
    CargoTrackingSystem(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Kargo Takip Sistemi");


        QLabel *nameLabel = new QLabel("Alıcı Adı:", this);
        nameLineEdit = new QLineEdit(this);

        QLabel *trackingLabel = new QLabel("Kargo Takip Numarası:", this);
        trackingLineEdit = new QLineEdit(this);

        QLabel *locationLabel = new QLabel("Kargo Lokasyonu:", this);
        locationLineEdit = new QLineEdit(this);

        QLabel *typeLabel = new QLabel("Kargo Türü:", this);
        typeLineEdit = new QLineEdit(this);

        QLabel *staffLabel = new QLabel("Personel:", this);
        staffComboBox = new QComboBox(this);
        staffComboBox->addItem("Personel A");
        staffComboBox->addItem("Personel B");
        staffComboBox->addItem("Personel C");

        QLabel *deliveryLabel = new QLabel("Teslim Tarihi ve Saati:", this);
        deliveryDateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(), this);

        QPushButton *trackButton = new QPushButton("Takip Et", this);
        QPushButton *clearButton = new QPushButton("Temizle", this);


        resultTextEdit = new QTextEdit(this);
        resultTextEdit->setReadOnly(true);


        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        mainLayout->addWidget(nameLabel);
        mainLayout->addWidget(nameLineEdit);

        mainLayout->addWidget(trackingLabel);
        mainLayout->addWidget(trackingLineEdit);

        mainLayout->addWidget(locationLabel);
        mainLayout->addWidget(locationLineEdit);

        mainLayout->addWidget(typeLabel);
        mainLayout->addWidget(typeLineEdit);

        mainLayout->addWidget(staffLabel);
        mainLayout->addWidget(staffComboBox);

        mainLayout->addWidget(deliveryLabel);
        mainLayout->addWidget(deliveryDateTimeEdit);

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        buttonLayout->addWidget(trackButton);
        buttonLayout->addWidget(clearButton);

        mainLayout->addLayout(buttonLayout);
        mainLayout->addWidget(resultTextEdit);

        setLayout(mainLayout);


        connect(trackButton, &QPushButton::clicked, this, &CargoTrackingSystem::trackCargo);
        connect(clearButton, &QPushButton::clicked, this, &CargoTrackingSystem::clearInputFields);
    }

private slots:
    void trackCargo() {
        if (!validateInput()) {
            return;
        }


        CargoInfo cargo;
        cargo.name = nameLineEdit->text();
        cargo.trackingNumber = trackingLineEdit->text();
        cargo.location = locationLineEdit->text();
        cargo.type = typeLineEdit->text();
        cargo.staff = staffComboBox->currentText();
        cargo.deliveryDateTime = deliveryDateTimeEdit->dateTime();


        QString result = "Alıcı Adı: " + cargo.name + "\n"
                                                      "Kargo Takip Numarası: " + cargo.trackingNumber + "\n"
                                                  "Lokasyon: " + cargo.location + "\n"
                                            "Kargo Türü: " + cargo.type + "\n"
                                        "Personel: " + cargo.staff + "\n"
                                         "Teslim Tarihi ve Saati: " + cargo.deliveryDateTime.toString("dd.MM.yyyy hh:mm:ss");


        resultTextEdit->setPlainText(result);
    }

    void clearInputFields() {

        nameLineEdit->clear();
        trackingLineEdit->clear();
        locationLineEdit->clear();
        typeLineEdit->clear();
        resultTextEdit->clear();
    }

private:
    QLineEdit *nameLineEdit;
    QLineEdit *trackingLineEdit;
    QLineEdit *locationLineEdit;
    QLineEdit *typeLineEdit;
    QComboBox *staffComboBox;
    QDateTimeEdit *deliveryDateTimeEdit;
    QTextEdit *resultTextEdit;

    bool validateInput() {

        if (nameLineEdit->text().isEmpty() || trackingLineEdit->text().isEmpty() ||
            locationLineEdit->text().isEmpty() || typeLineEdit->text().isEmpty()) {

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
