#include "bank_account.h"
#include <stdexcept>

namespace Bankaccount {

void Bankaccount::open()
{
    if (m_isActive)
        throw std::runtime_error("Account is already open.");
    
    m_isActive = true;
}

void Bankaccount::close()
{
    if (!m_isActive)
        throw std::runtime_error("Account is closed.");

    m_isActive = false;
    m_money = 0;
}
    
int Bankaccount::balance()
{
    if (!m_isActive)
        throw std::runtime_error("Account is closed.");
    
    return m_money;
}

void Bankaccount::deposit(int value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_isActive)
        throw std::runtime_error("Account is closed.");
    if (value < 0)
        throw std::runtime_error("Deposit value should not be negative.");
    
    m_money += value;
}

void Bankaccount::withdraw(int value)
{
    std::lock_guard<std::mutex> lock(m_mutex);
    
    if (!m_isActive)
        throw std::runtime_error("Account is closed.");
    if (value < 0)
        throw std::runtime_error("Deposit value should not be negative.");
    if (m_money - value < 0)
        throw std::runtime_error("Not enought money to withdraw.");
    
    m_money -= value;
}
    
}