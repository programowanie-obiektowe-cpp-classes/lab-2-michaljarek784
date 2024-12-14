#pragma once

#include "Resource.hpp"

class ResourceManager
{
    private:
    std::unique_ptr<Resource> resource;// Wskaźnik do zasobu

    public:
    ResourceManager() : resource(std::make_unique<Resource>()) {} // konstruktor domyślny - inicjalizuje zasób przy pomocy konstruktora Resource

    // Metoda get(), która wywołuje metodę get() obiektu Resource
    double get() const {
        return resource->get();
    }

    // Domyślny konstruktor kopiujący i operator przypisania są usuwane, aby uniknąć kopiowania zasobu, który jest drogi w konstrukcji.
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;

    // Konstruktor przenoszący - przenosi zasób z obiektu innego ResourceManager
    ResourceManager(ResourceManager&& other) noexcept 
        : resource(std::move(other.resource)) {} // Przenosi zasób

    // Operator przypisania przenoszącego - przenosi zasób z innego obiektu
    ResourceManager& operator=(ResourceManager&& other) noexcept {
        if (this != &other) { 
            resource = std::move(other.resource); // Przenosi zasób
        }
        return *this;
    }
};


