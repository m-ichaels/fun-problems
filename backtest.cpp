#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

struct StockData {
    double price;
    double volatility;
    double return_info;
    bool should_buy;
};

vector<StockData> stock_data = {
    {150.0, 0.2, 0.1, true},
    {120.0, 0.15, 0.08, false},
    {180.0, 0.3, 0.2, true}
};
double current_money = 100000;
mutex money_mutex;

void buyStock(StockData &stock) {
    lock_guard<mutex> lock(money_mutex);
    if (stock.should_buy && current_money >= stock.price) {
        current_money -= stock.price;
        cout << "Bought stock for " << stock.price << " dollars" << endl;
    }
}

void sellStock(StockData &stock) {
    lock_guard<mutex> lock(money_mutex);
    if (!stock.should_buy) {
        current_money += stock.price;
        cout << "Sold stock for " << stock.price << " dollars" << endl;
    }
}

int main() {
    vector<thread> threads;

    for (int i = 0; i < stock_data.size(); i++) {
        StockData &stock = stock_data[i];
        threads.push_back(thread(buyStock, ref(stock)));
        threads.push_back(thread(sellStock, ref(stock)));
    }

    for (int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

    cout << "Final money: " << current_money << " dollars" << endl;
    return 0;
}