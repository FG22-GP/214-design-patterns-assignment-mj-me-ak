#pragma once
#include <vector>

#include "Observer.h"
#include "../GameObjects/Component.h"

class Subject : Component
{
private:
    std::vector<Observer*> observers;

protected:
    void Notify(const GameObject& gameObject);
    
public:
    void AddObserver(Observer* observer);

    void RemoveObserver(Observer* observer);
    
};