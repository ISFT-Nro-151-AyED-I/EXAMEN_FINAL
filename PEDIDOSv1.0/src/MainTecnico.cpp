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

// Función para mostrar el encabezado de la aplicación.
void mostrarEncabezado();

int main() 
    {
        // Configura consola para caracteres especiales.
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
        
        mostrarEncabezado();
        
        std::cout << "\n🚀 INICIALIZANDO SISTEMA DE PEDIDOS v1.0...\n";
        std::cout << "============================================\n\n";
        
        // 1. CREACIÓN DE EMPRESA (Punto 6: uso de punteros).
        std::cout << "🏢 CREANDO EMPRESA (COMPOSICIÓN)...\n";
        std::cout << "====================================\n\n";
        
        Empresa* miEmpresa = new Empresa("TechSolutions S.A.");

        // 2. EMPRESA CREA SUCURSAL (COMPOSICIÓN).
        std::cout << "\n📍 EMPRESA CREANDO SUCURSAL (COMPOSICIÓN)...\n";
        std::cout << "=============================================\n\n";
        
        Sucursal* sucursalCentral = miEmpresa->crearSucursal("Sucursal Centro", "Av. Luro 324");
        
        std::cout << "\n✅ Empresa y sucursal creadas exitosamente.\n\n";
        
        // 3. CREACIÓN DE 3 VENDEDORES DE DIFERENTES TIPOS.
        std::cout << "👥 CREANDO 3 VENDEDORES (AGREGACIÓN - PUNTO 5)...\n";
        std::cout << "==================================================\n\n";
        
        std::cout << "📝 Main.cpp creando vendedores (AGREGACIÓN):\n\n";
        
        // Vendedor 1: Particular (creado por Main.cpp).
        std::cout << "🚗 VENDEDOR PARTICULAR #1\n";
        std::cout << "--------------------------\n\n";
        VendedorParticular* vendedor1 = new VendedorParticular
            (
                "José Coder", 
                "jose.coder@empresa.com", 
                2500.00, 
                "Ventas al Detalle"
            );
        sucursalCentral->agregarVendedor(vendedor1); // AGREGACIÓN.
        
        std::cout << std::endl;
        
        // Vendedor 2: Profesional (creado por Main.cpp).
        std::cout << "🎓 VENDEDOR PROFESIONAL #2\n";
        std::cout << "--------------------------\n\n";
        VendedorProfesional* vendedor2 = new VendedorProfesional
            (
                "Macarena Cosabuena", 
                "macarena.cosabuena@empresa.com", 
                3200.00, 
                "Ventas Corporativas"
            );
        sucursalCentral->agregarVendedor(vendedor2); // AGREGACIÓN.
        
        std::cout << std::endl;
        
        // Vendedor 3: Empresa (creado por Main.cpp).
        std::cout << "🏢 VENDEDOR DE EMPRESA #3\n";
        std::cout << "--------------------------\n\n";
        VendedorEmpresa* vendedor3 = new VendedorEmpresa
            (
                "Matías Santo", 
                "matias.santo@empresa.com", 
                2800.00, 
                "Cuentas Clave"
            );
        sucursalCentral->agregarVendedor(vendedor3); // AGREGACIÓN.
        
        std::cout << "\n✅ Los 3 vendedores han sido creados por Main.cppy agregados a la sucursal.\n\n";
        
        // 4. PUNTO 5: VENDEDORES TRABAJANDO POLIMÓRFICAMENTE.
        std::cout << "\n👨‍💼 VENDEDORES TRABAJANDO (POLIMORFISMO)...\n";
        std::cout << "===========================================\n\n";
        
        std::cout << "🕐 INICIANDO JORNADA LABORAL:\n\n";
        
        // Array de punteros base para demostrar polimorfismo.
        Empleado* empleados[3] = {vendedor1, vendedor2, vendedor3};
        
        // Cada vendedor trabaja de manera diferente (polimorfismo).
        for (int i = 0; i < 3; i++) 
            {
                empleados[i]->trabajar();  // Llamada polimórfica.
            }
        
        std::cout << "\n✅ Todos los vendedores están trabajando (demostración de polimorfismo).\n\n";
        
        // 5. PUNTO 6: USO DE PUNTEROS - LISTAR INFORMACIÓN.
        std::cout << "\n📊 INFORMACIÓN DEL SISTEMA (USO DE PUNTEROS)...\n";
        std::cout << "================================================\n\n";
        
        std::cout << "🏢 INFORMACIÓN DE LA EMPRESA:\n\n";
        miEmpresa->listarSucursales();
        
        std::cout << "\n📍 INFORMACIÓN DE LA SUCURSAL CENTRAL:\n\n";
        std::cout << "   Nombre: " << sucursalCentral->getNombre() << std::endl;
        std::cout << "   Dirección: " << sucursalCentral->getDireccion() << std::endl;
        std::cout << "   Cantidad de Vendedores: " << sucursalCentral->getCantidadVendedores() << std::endl;
        
        // 6. PUNTO 7: RECORRER EMPLEADOS POLIMÓRFICAMENTE.
        std::cout << "\n🔍 RECORRIDO POLIMÓRFICO DE EMPLEADOS (Punto 7)...\n";
        std::cout << "===================================================\n\n";
        
        std::cout << "📋 LISTA COMPLETA DE VENDEDORES CON DATOS POLIMÓRFICOS:\n\n";
        
        for (int i = 0; i < 3; i++) 
            {
                std::cout << "👤 VENDEDOR #" << (i + 1) << ":\n";
                std::cout << "------------------------------\n\n";
                
                // Método polimórfico: mostrarDatos() - cada vendedor muestra datos diferentes.
                empleados[i]->mostrarDatos();
                
                // Método polimórfico: calcularSalarioTotal() - cada tipo calcula diferente.
                std::cout << "   💰 Salario Total: $" << empleados[i]->calcularSalarioTotal() 
                        << " (Base: $" << empleados[i]->getSalarioBase() << " + bonos).\n";
                
                // Método polimórfico: obtenerTipo() - cada tipo retorna string diferente.
                std::cout << "   🏷️  Tipo: " << empleados[i]->obtenerTipo() << std::endl;
                
                // Datos comunes (no polimórficos).
                std::cout << "   📧 Email: " << empleados[i]->getEmail() << std::endl;
                std::cout << "   📍 Área: " << empleados[i]->getAreaAsignada() << std::endl;
                
                std::cout << std::endl;
            }
        
        // 7. ENVÍO DE NOTIFICACIONES.
        std::cout << "\n📢 ENVÍO DE NOTIFICACIONES...\n";
        std::cout << "===============================================\n\n";
        
        std::cout << "🔔 Enviando notificación a todos los vendedores:\n";
        sucursalCentral->enviarNotificacionATodos("¡Reunión importante mañana a las 17:30 PM!");
        
        std::cout << "\n✅ Notificación enviada a todos los vendedores.\n\n";
        
        // 8. LISTAR VENDEDORES DESDE LA SUCURSAL
        std::cout << "\n📋 LISTADO DESDE SUCURSAL...\n";
        std::cout << "===============================================\n\n";
        
        sucursalCentral->listarVendedores();
        
        // 9. DEMOSTRACIÓN FINAL: RESUMEN DEL SISTEMA.
        std::cout << "\n📈 RESUMEN FINAL DEL SISTEMA...\n";
        std::cout << "===============================================\n\n";
        
        std::cout << "🏢 EMPRESA: " << miEmpresa->getNombre() << std::endl;
        std::cout << "📍 SUCURSAL: " << sucursalCentral->getNombre() << std::endl;
        std::cout << "👥 TOTAL VENDEDORES: " << sucursalCentral->getCantidadVendedores() << std::endl;
        std::cout << "💰 NÓMINA TOTAL APROXIMADA: $" 
                << (vendedor1->calcularSalarioTotal() + 
                    vendedor2->calcularSalarioTotal() + 
                    vendedor3->calcularSalarioTotal()) 
                << "/mes\n\n";
        
        // 10. LIMPIEZA DE MEMORIA.
        std::cout << "\n\n===============================================\n";
        std::cout << "   🧹 LIBERANDO MEMORIA (DESTRUCTORES)...\n";
        std::cout << "===============================================\n\n";

        std::cout << "📋 ORDEN DE ELIMINACIÓN:\n";
        std::cout << "   1. Empleados (AGREGACIÓN - creados por main.cpp)\n";
        std::cout << "   2. Empresa (COMPOSICIÓN - eliminará sucursales)\n\n";
        
        // 10.1. ELIMINAR EMPLEADOS (agregación - main.cpp los creó).
        std::cout << "🗑️  1. Eliminando empleados (AGREGACIÓN)...\n";

        delete vendedor1;
        delete vendedor2;
        delete vendedor3;

        std::cout << "✅ Vendedores liberados.\n";
        
        // 10.2. ELIMINAR EMPRESA (composición - eliminará sucursales).
        std::cout << "🗑️  2. Eliminando empresa (COMPOSICIÓN - eliminará sucursales automáticamente)...\n";
        delete miEmpresa;  // Esto llamará al destructor que elimina Sucursales.
        std::cout << "✅  Empresa y sus sucursales liberadas.\n\n";
        
        // RESUMEN.
        std::cout << "═══════════════════════════════════════════════\n";
        std::cout << "🎯 RELACIONES IMPLEMENTADAS CORRECTAMENTE:\n";
        std::cout << "═══════════════════════════════════════════════\n\n";
        std::cout << "🏢 Empresa → Sucursal: COMPOSICIÓN ✓\n";
        std::cout << "   • Empresa crea sucursales (crearSucursal())\n";
        std::cout << "   • Empresa elimina sucursales (destructor)\n\n";
        std::cout << "📍 Sucursal → Empleado: AGREGACIÓN ✓\n";
        std::cout << "   • Main.cpp crea empleados\n";
        std::cout << "   • Sucursal solo contiene punteros\n";
        std::cout << "   • Main.cpp elimina empleados\n\n";
        
        std::cout << "===============================================\n";
        std::cout << "   🎉 PROGRAMA EJECUTADO EXITOSAMENTE! 🎉\n";
        std::cout << "===============================================\n";
        
        std::cout << "\n\nPresiona Enter para salir...";
        std::cin.get();
        
        return 0;
    }

void mostrarEncabezado() 
    {
        std::cout << "\n✨ =============================================== ✨\n";
        std::cout << "✨            SISTEMA DE PEDIDOS v1.0 🛒           ✨\n";
        std::cout << "✨     Demostración Hardcore - POO en C++          ✨\n";
        std::cout << "✨ =============================================== ✨\n\n";
    }