#pragma once
#include <mutex>

namespace Bankaccount {
class Bankaccount {
public:
    void open();
    void close();
    int balance();
    void deposit(int value);
    void withdraw(int value);

private:
    bool m_isActive = false;
    int m_money = 0;
    std::mutex m_mutex;
    
};  // class Bankaccount

}  // namespace Bankaccount
