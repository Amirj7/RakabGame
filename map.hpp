#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class CityMap
{
public:
    CityMap()
    {
        nearbyCities["BELLA"] = {"CALINE", "PLADACI", "BORGE"};
        nearbyCities["CALINE"] = {"BELLA", "BORGE", "LIA", "ATELA", "PLADACI"};
        nearbyCities["LIA"] = {"CALINE", "ATELA", "BORGE", "DAMASE"};
        nearbyCities["ATELA"] = {"CALINE", "LIA", "DIMASE", "ATHENS"};
        nearbyCities["PLADACI"] = {"BELLA", "CALINE", "BORGE", "MORINA", "ROLLO"};
        nearbyCities["BORGE"] = {"BELLA", "CALINE", "LIA", "DIMASE", "PLADACI", "MORINA", "OLIVADI"};
        nearbyCities["DIMASE"] = {"ATELA", "LIA", "BORGE", "OLIVADI", "ATHENS"};
        nearbyCities["MORINA"] = {"PLADACI", "BORGE", "OLIVADI", "ARMENTO", "TALMONE", "ROLLO"};
        nearbyCities["OLIVADI"] = {"DIMASE", "BORGE", "MORINA", "ARMENTO", "ENNA"};
        nearbyCities["ROLLO"] = {"PLADACI", "MORINA", "TALMONE", "ELINIA"};
        nearbyCities["TALMONE"] = {"MORINA", "ARMENTO", "ROLLO", "ELINIA"};
        nearbyCities["ARMENTO"] = {"MORINA", "OLIVADI", "ENNA", "TALMONE"};
        nearbyCities["ENNA"] = {"OLIVADI", "ARMENTO"};
        nearbyCities["ELINIA"] = {"ROLLO", "TALMONE"};
        nearbyCities["ATHENS"] = {"ATELA", "DIMASE"}; // new city added to the game
        // enna va lia jabeja shodan 
    }

    vector<string> getNearbyCities(string city)
    {
        if (nearbyCities.find(city) != nearbyCities.end())
        {
            return nearbyCities[city];
        }
        else
        {
            return {};
        }
    }

    bool isValidCity(const string &city) const
    {
        return nearbyCities.find(city) != nearbyCities.end();
    }

private:
    map<string, vector<string>> nearbyCities;
};