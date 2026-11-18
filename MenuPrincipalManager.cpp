///TPI G08 - MAI VersionCode
#include <iostream>
#include "MenuPrincipalManager.h"

///---- MAI - BARBI ----
using namespace std;
/**
MenuPrincipalManager::MenuPrincipalManager(){
    setCantidadOpciones(10);
}
void MenuPrincipalManager::mostrarOpciones(){
        cout << "==================================================" << endl;
        cout << "          SISTEMA DE GESTION DE LIBRERIA          " << endl;
        cout << "==================================================" << endl;
        cout << " 1. GESTION DE EMPLEADOS" << endl;
        cout << " 2. GESTION DE CLIENTES" << endl;
        cout << " 3. GESTION DE LIBROS" << endl;
        cout << " 4. GESTION DE GENEROS LITERARIOS" << endl;
        cout << " 5. GESTION DE AUTORES" << endl;
        cout << " 6. GESTION DE EDITORIALES" << endl;
        cout << " 7. GESTION DE VENTAS" << endl;
        cout << " 8. GESTION DE COMPRAS" << endl;
        cout << " 9. GESTION DE INFORMES" << endl;
        cout << " 10. CONFIGURACION" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << " 0. SALIR DEL SISTEMA" << endl;
        cout << "==================================================" << endl;

}

void MenuPrincipalManager::ejecutarOpcion(int opcion) {

     archObra.crearObrasSocialesPredeterminadas();
     //(Si tienen funciones similares para predeterminar Tipos de Orden U Origenes, las llamas aca)



        switch (opcion) {
            case 1:{
                em.run();
                break;
            }
            case 2:{
                clim.run();
                break;
            }
            case 3:{
                lm.menu();
                break;
            }
            case 4:{

                gm.menu();
                break;
            }
            case 5:{
                am.menu();
                break;
            }
            case 6: {
                edm.menu();
                break;
            }
            case 7:{
                vm.run();
                break;
            }
            case 8: {
                com.run();
                break;
            }
            case 9: {
                im.run();
                break;
            }
            case 10: {
                cm.run();
                break;

            case 0:
                cout << endl << "Gracias por usar el sistema. Saliendo..." << endl;
                break;
            default:
                cout << endl << "OPCION INCORRECTA. Intente nuevamente" << endl;
                system("pause");
                break;
        }
    }
*/
