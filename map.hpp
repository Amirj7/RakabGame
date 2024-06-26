#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class CityMap {
public:
    CityMap() {
        nearbyCities["BELLA"] = {"CALINE", "PLADACI", "BORGE"};
        nearbyCities["CALINE"] = {"BALLA", "BORGE", "ENNA", "ATELA", "PLADACI"};
        nearbyCities["ENNA"] = {"CALINE", "ATELA", "BORGE", "DAMASE"};
        nearbyCities["ATELA"] = {"CALINE", "ENNA", "DIMASE"};
        nearbyCities["PLADACI"] = {"BALLA", "CALINE", "BORGE", "MORINA", "ROLLO"};
        nearbyCities["BORGE"] = {"BALLA", "CALINE", "ENNA", "DIMASE", "PLADACI", "MORINA", "OLIVADI"};
        nearbyCities["DIMASE"] = {"ATELA", "ENNA", "BORGE", "OLIVADI"};
        nearbyCities["MORINA"] = {"PLADACI", "BORGE", "OLIVADI", "ARMENTO", "TALMONE", "ROLLO"};
        nearbyCities["OLIVADI"] = {"DIMASE", "BORGE", "MORINA", "ARMENTO", "LIA"};
        nearbyCities["ROLLO"] = {"PLADACI", "MORINA", "TALMONE", "ELINIA"};
        nearbyCities["TALMONE"] = {"MORINA", "ARMENTO", "ROLLO", "ELINIA"};
        nearbyCities["ARMENTO"] = {"MORINA", "OLIVADI", "LIA", "TALMONE"};
        nearbyCities["LIA"] = {"OLIVADI", "ARMENTO"};
        nearbyCities["ELINIA"] = {"ROLLO", "TALMONE"};
    }

    vector<string> getNearbyCities(string city) {
        if (nearbyCities.find(city)!= nearbyCities.end()) {
            return nearbyCities[city];
        } else {
            return {};
        }
    }

private:
    map<string, vector<string>> nearbyCities;
};