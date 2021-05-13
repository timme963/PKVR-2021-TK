#include "analysisObstacles.h"
#include <memory>

/*PROTECTED REGION ID(inccpp1611833222383) ENABLED START*/
    //Add additional includes here
    #include "model/worldmodel.h"
/*PROTECTED REGION END*/

namespace alica
{
    /*PROTECTED REGION ID(staticVars1611833222383) ENABLED START*/
    //initialise static variables here
    /*PROTECTED REGION END*/

    analysisObstacles::analysisObstacles() : DomainBehaviour("analysisObstacles")
    {
        /*PROTECTED REGION ID(con1611833222383) ENABLED START*/
        //Add additional options here
        wm = alica_agent::model::WorldModel::getInstance();
        /*PROTECTED REGION END*/

    }
    analysisObstacles::~analysisObstacles()
    {
        /*PROTECTED REGION ID(dcon1611833222383) ENABLED START*/
        //Add additional options here
        /*PROTECTED REGION END*/

    }
    void analysisObstacles::run(void* msg)
    {
        /*PROTECTED REGION ID(run1611833222383) ENABLED START*/
        //Add additional options here
        int ** obstacles = wm->terrain.obstacle;
        int vision = wm->gameconf.vision;
        std::cout << "analyse: " << std::endl;
        for (int i = 0; i <  vision * 2 + 1; ++i){
            for (int j = 0; j <  vision * 2 + 1; ++j){
                    int xRel = i - vision;
                    int yRel = j - vision;
                    if(wm->terrain.obstacle[i][j] == -1){
                        continue;
                    }
                    wm->world.updateObstacle(wm->terrain.obstacle[i][j], xRel, yRel);
                    
            }
        }
        wm->world.printWorld();
        /*PROTECTED REGION END*/

    }
    void analysisObstacles::initialiseParameters()
    {
        /*PROTECTED REGION ID(initialiseParameters1611833222383) ENABLED START*/
        //Add additional options here

        /*PROTECTED REGION END*/

    }
    /*PROTECTED REGION ID(methods1611833222383) ENABLED START*/
        //Add additional options here
    /*PROTECTED REGION END*/

} /* namespace alica */
