#include <iostream>
#include <windows.h>
#include <string>

#include "../include/Empresa.hpp"
#include "../include/Sucursal.hpp"
#include "../include/Empleado.hpp"
#include "../include/VendedorParticular.hpp"
#include "../include/VendedorProfesional.hpp"
#include "../include/VendedorEmpresa.hpp"

using namespace Pedidos;

void mostrarEncabezado();

int main() 
    {
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        mostrarEncabezado();
        
        std::cout << "\n🚀 INICIALIZANDO SISTEMA DE PEDIDOS v1.0...\n";
        std::cout << "============================================\n\n";
        
        // 1. CREACIÓN DE EMPRESA.
        std::cout << "🏢 CREANDO EMPRESA...\n";
        std::cout << "====================================\n\n";
        
        Empresa* miEmpresa = new Empresa("TechSolutions S.A.");

        // 2. CREACIÓN DE SUCURSAL.
        std::cout << "\n📍 CREANDO SUCURSAL...\n";
        std::cout << "=============================================\n\n";
        
        Sucursal* sucursalCentral = miEmpresa->crearSucursal("Sucursal Centro", "Av. Luro 324");
        
        std::cout << "\n✅ Empresa y sucursal creadas exitosamente.\n\n";
        
        // 3. CREACIÓN DE VENDEDORES.
        std::cout << "👥 CREANDO VENDEDORES...\n";
        std::cout << "==================================================\n\n";
        
        // Vendedor Particular.
        std::cout << "🚗 VENDEDOR PARTICULAR\n";
        std::cout << "--------------------------\n\n";
        VendedorParticular* vendedor1 = new VendedorParticular
            (
                "José Coder", 
                "jose.coder@empresa.com", 
                2500.00, 
                "Ventas al Detalle"
            );
        sucursalCentral->agregarVendedor(vendedor1);
        
        std::cout << std::endl;
        
        // Vendedor Profesional.
        std::cout << "🎓 VENDEDOR PROFESIONAL\n";
        std::cout << "--------------------------\n\n";
        VendedorProfesional* vendedor2 = new VendedorProfesional
            (
                "Macarena Cosabuena", 
                "macarena.cosabuena@empresa.com", 
                3200.00, 
                "Ventas Corporativas"
            );
        sucursalCentral->agregarVendedor(vendedor2);
        
        std::cout << std::endl;
        
        // Vendedor Empresa.
        std::cout << "🏢 VENDEDOR DE EMPRESA\n";
        std::cout << "--------------------------\n\n";
        VendedorEmpresa* vendedor3 = new VendedorEmpresa
            (
                "Matías Santo", 
                "matias.santo@empresa.com", 
                2800.00, 
                "Cuentas Clave"
            );
        sucursalCentral->agregarVendedor(vendedor3);
        
        std::cout << "\n✅ Vendedores agregados al sistema.\n\n";
        
        // 4. VENDEDORES EN ACCIÓN.
        std::cout << "\n👨‍💼 VENDEDORES TRABAJANDO...\n";
        std::cout << "===========================================\n\n";
        
        std::cout << "🕐 INICIANDO JORNADA LABORAL:\n\n";
        
        Empleado* empleados[3] = {vendedor1, vendedor2, vendedor3};
        
        for (int i = 0; i < 3; i++) 
            {
                empleados[i]->trabajar();
            }
        
        std::cout << "\n✅ Jornada laboral completada.\n\n";
        
        // 5. INFORMACIÓN DEL SISTEMA.
        std::cout << "\n📊 INFORMACIÓN DEL SISTEMA...\n";
        std::cout << "================================================\n\n";
        
        std::cout << "🏢 EMPRESA:\n\n";
        miEmpresa->listarSucursales();
        
        std::cout << "\n📍 SUCURSAL CENTRAL:\n\n";
        std::cout << "   Nombre: " << sucursalCentral->getNombre() << std::endl;
        std::cout << "   Dirección: " << sucursalCentral->getDireccion() << std::endl;
        std::cout << "   Vendedores: " << sucursalCentral->getCantidadVendedores() << std::endl;
        
        // 6. LISTA DE VENDEDORES.
        std::cout << "\n🔍 LISTA DE VENDEDORES...\n";
        std::cout << "===================================================\n\n";
        
        std::cout << "📋 DATOS COMPLETOS:\n\n";
        
        for (int i = 0; i < 3; i++) 
            {
                std::cout << "👤 VENDEDOR #" << (i + 1) << ":\n";
                std::cout << "------------------------------\n\n";
                
                empleados[i]->mostrarDatos();
            
                std::cout << "   💰 Salario Total: $" << empleados[i]->calcularSalarioTotal() 
                    << " (Base: $" << empleados[i]->getSalarioBase() << " + bonos).\n";
            
                std::cout << "   🏷️  Tipo: " << empleados[i]->obtenerTipo() << std::endl;
                std::cout << "   📧 Email: " << empleados[i]->getEmail() << std::endl;
                std::cout << "   📍 Área: " << empleados[i]->getAreaAsignada() << std::endl;
            
                std::cout << std::endl;
            }
        
        // 7. NOTIFICACIONES.
        std::cout << "\n📢 ENVÍO DE NOTIFICACIONES...\n";
        std::cout << "===============================================\n\n";
        
        std::cout << "🔔 Notificación a todos los vendedores:\n";
        sucursalCentral->enviarNotificacionATodos("¡Reunión importante mañana a las 17:30 PM!");
        
        std::cout << "\n✅ Notificación enviada.\n\n";
        
        // 8. LISTADO DESDE SUCURSAL.
        std::cout << "\n📋 LISTADO DESDE SUCURSAL...\n";
        std::cout << "===============================================\n\n";
        
        sucursalCentral->listarVendedores();
        
        // 9. RESUMEN FINAL.
        std::cout << "\n📈 RESUMEN FINAL...\n";
        std::cout << "===============================================\n\n";
        
        std::cout << "🏢 EMPRESA: " << miEmpresa->getNombre() << std::endl;
        std::cout << "📍 SUCURSAL: " << sucursalCentral->getNombre() << std::endl;
        std::cout << "👥 TOTAL VENDEDORES: " << sucursalCentral->getCantidadVendedores() << std::endl;
        std::cout << "💰 NÓMINA TOTAL: $" 
                  << (vendedor1->calcularSalarioTotal() + 
                      vendedor2->calcularSalarioTotal() + 
                      vendedor3->calcularSalarioTotal()) 
                  << "/mes\n\n";
        
        // 10. FINALIZACIÓN.
        std::cout << "\n\n===============================================\n";
        std::cout << "         🧹 FINALIZANDO SISTEMA...\n";
        std::cout << "===============================================\n\n";

        std::cout << "🗑️  Liberando recursos del sistema...\n";

        delete vendedor1;
        delete vendedor2;
        delete vendedor3;
        delete miEmpresa;

        std::cout << "✅ Sistema finalizado correctamente.\n\n";
        
        std::cout << "===============================================\n";
        std::cout << "   🎉 SISTEMA EJECUTADO EXITOSAMENTE! 🎉\n";
        std::cout << "===============================================\n";
        
        std::cout << "\n\nPresiona Enter para salir...";
        std::cin.get();
        
        return 0;
    }

void mostrarEncabezado() 
    {
        std::cout << "\n✨ =============================================== ✨\n";
        std::cout << "✨            SISTEMA DE PEDIDOS v1.0 🛒           ✨\n";
        std::cout << "✨     Gestión Comercial - TechSolutions S.A.      ✨\n";
        std::cout << "✨ =============================================== ✨\n\n";
    }