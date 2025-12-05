#pragma once

#include "Empleado.hpp"

namespace Pedidos 
    {
        class VendedorParticular : public Empleado 
            {
                private:
                    bool tieneVehiculoPropio;

                public:
                    // Constructor y destructor.
                    VendedorParticular(const std::string& nombre, const std::string& email,
                                       double salarioBase, const std::string& areaAsignada);
                    ~VendedorParticular() override;

                    // Implementación de métodos virtuales.
                    void trabajar() override;
                    void mostrarDatos() const override;
                    void recibirNotificacion(const std::string& mensaje) override;
                    double calcularSalarioTotal() const override;
                    std::string obtenerTipo() const override;

                    // Getter.
                    bool getTieneVehiculoPropio() const;
            };
    }