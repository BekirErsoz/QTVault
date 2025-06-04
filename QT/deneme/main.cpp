#include <QTextStream>
#include <stdexcept>
#include <QString>

class Package {
public:
    Package(const QString& senderName, const QString& senderAddress, const QString& senderCity,
            const QString& senderState, const QString& receiverName, const QString& receiverAddress,
            const QString& receiverCity, const QString& receiverState, int senderZipcode,
            int receiverZipcode, double weight, double cost);

    void setSName(const QString& senderName);
    QString getSName() const;

    // Diğer üye fonksiyonlar...

    QString toString() const;

private:
    QString sName;
    QString sAddress;
    QString sCity;
    QString sState;
    QString rName;
    QString rAddress;
    QString rCity;
    QString rState;
    int sZipcode;
    int rZipcode;
    double weight;
    double cost;

    void setWeight(double w);
    void setCost(double c);
    double calculateCost() const;
};

Package::Package(const QString& senderName, const QString& senderAddress, const QString& senderCity,
                 const QString& senderState, const QString& receiverName, const QString& receiverAddress,
                 const QString& receiverCity, const QString& receiverState, int senderZipcode,
                 int receiverZipcode, double weight, double cost)
    : sName(senderName), sAddress(senderAddress), sCity(senderCity), sState(senderState),
    rName(receiverName), rAddress(receiverAddress), rCity(receiverCity), rState(receiverState),
    sZipcode(senderZipcode), rZipcode(receiverZipcode), weight(weight), cost(cost) {
    setWeight(weight);
    setCost(cost);
}

void Package::setWeight(double w) {
    if (w < 0.0) {
        throw std::invalid_argument("Weight must be more than 0");
    }

    weight = w;
}

double Package::calculateCost() const {
    return weight * cost;
}

void Package::setCost(double c) {
    if (c < 0.0) {
        throw std::invalid_argument("Cost must be more than 0");
    }

    cost = c;
}

// Diğer üye fonksiyonları da implemente edin...

QString Package::toString() const {
    QTextStream stream;
    stream.setRealNumberPrecision(2);
    stream << "Sender Name: " << sName << "\nAddress: " << sAddress << " " << sCity << " "
           << sState << " " << sZipcode << "\n"
           << "Receiver Name: " << rName << "\nAddress: " << rAddress << " " << rCity << " "
           << rState << " " << rZipcode << "\n"
           << "The cost of the regular package: " << calculateCost() << "\n";
    return stream.readAll();
}
