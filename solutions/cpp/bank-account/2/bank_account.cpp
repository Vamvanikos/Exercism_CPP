#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {

void Bankaccount::open()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_active)
        throw std::runtime_error("The account is already open.");

    m_active = true;
}
    
void Bankaccount::close()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    throw_inactive();
    
    m_active = false;
    m_balance = 0;
}
    
int Bankaccount::balance()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    throw_inactive();
    
    return m_balance;
}
    
void Bankaccount::deposit(int value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    throw_inactive();
    if (value < 0)
        throw std::runtime_error("The deposit value can't be negative.");

    m_balance += value;
}
    
void Bankaccount::withdraw(int value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    throw_inactive();
    if (value < 0)
        throw std::runtime_error("The withdraw value can't be negative.");
    if (value > m_balance)
        throw std::runtime_error("The withdraw value can't be greater than the balance.");

    m_balance -= value;
}

void Bankaccount::throw_inactive() const 
{
    if (!m_active)
        throw std::runtime_error("The account is currently closed.");
}
    
}