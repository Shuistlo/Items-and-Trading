#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
using pep::vector;


class Trade {
protected:
    int buyTime; //lowest one
    int sellTime; //highest one

public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }
};

Trade bestBuySellTime(vector<int> prices){
    int currentHighestBuy = 0;
    int currentHighestSell = 0;
    int currentHighestProfit = 0;

    int currentBuy = 0;
    int currentSell=0;
    int currentProfit=0;

    while(currentBuy < prices.size()){
        currentSell = currentBuy;
        currentProfit = 0;
        while(currentSell < prices.size() && prices[currentSell] >= prices[currentBuy]){
            currentProfit = prices[currentSell] - prices[currentBuy];
            if(currentProfit > currentHighestProfit){
		currentHighestBuy = currentBuy;
                currentHighestSell = currentSell;
                currentHighestProfit = prices[currentHighestSell] - prices[currentHighestBuy];
            }
            currentSell++;
        }
        currentBuy = currentSell;
    }
    return Trade(currentHighestBuy, currentHighestSell);
}

// TODO your code goes here:













// Don't write any code below this line

#endif
