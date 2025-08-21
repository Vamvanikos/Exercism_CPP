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
    void throw_inactive() const;
    
    bool m_active = false;
    int m_balance = 0;
    std::mutex m_mutex;
    
};  // class Bankaccount

}  // namespace Bankaccount
