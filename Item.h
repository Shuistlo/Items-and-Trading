#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;
using std::ostream;
#include <cmath>

// TODO: your code goes here

class Item{
protected:
    double lat;
    double longt;
    string ID;
    int time;

public:
    Item(const double latIn, const double longtIn, const string &IDIn, const int timeIn)
        : lat(latIn), longt(longtIn), ID(IDIn), time(timeIn){
    }

    std::string doubleToString(double d) const {
            std::string result = std::to_string(d);
            //check for trailing zeroes iff there is a dot
            //we want to turn "0.10" into "0.1"
            //we don't want to turn "10" into "1"
            if (result.find('.') != result.size()) {
                    result.erase(result.find_last_not_of('0') + 1, std::string::npos);
            }
            //iff the last character is a ".", remove it
            //e.g. if original string was "10.0", then it is now "10."
            if (result.find('.') == result.size() - 1) {
                    result = result.substr(0, result.size() - 1);
            }
            return result;
    }
    std::string toString() const {
            return "{" + doubleToString(getLat()) + ", " + doubleToString(getLongt()) + ", \"" + getID() + "\", " + doubleToString(getTime()) + "}";
    }
    double getLat() const {
        return lat;
    }

    double getLongt() const {
        return longt;
    }

    string getID() const {
        return ID;
    }

    int getTime() const {
        return time;
    }

    double distanceTo(Item const &other) const {
        double lon2 = other.getLongt();
        double lat2 = other.getLat();

        double dlon = (lon2 - longt)*(M_PI/180);
        double dlat = (lat2 - lat)*(M_PI/180);
        double a = pow(sin(dlat/2), 2) + cos(lat*(M_PI/180)) * cos(lat2*(M_PI/180)) * pow(sin(dlon/2), 2);
        double c = 2 * atan2(sqrt(a), sqrt(1-a));
        double distance =  6373000 * c;

        return distance;
    }
};
ostream & operator<<(ostream &o, const Item & itm){
    o << itm.toString();
    return o;
}
// don't write any code below this line

#endif
