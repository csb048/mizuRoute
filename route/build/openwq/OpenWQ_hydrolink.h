// This program, openWQ, is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) aNCOLS later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef OPENWQ_HYDROLINK_INCLUDED
#define OPENWQ_HYDROLINK_INCLUDED

#include "openwq/src/couplercalls/OpenWQ_couplercalls.hpp"
#include "openwq/src/global/OpenWQ_hostModelconfig.hpp"
#include "openwq/src/readjson/OpenWQ_readjson.hpp"
#include "openwq/src//initiate/OpenWQ_initiate.hpp"
#include "openwq/src/chem/OpenWQ_chem.hpp"
#include "openwq/src/watertransp/OpenWQ_watertransp.hpp"
#include "openwq/src/extwatflux_ss/OpenWQ_extwatflux_ss.hpp"
#include "openwq/src/units/OpenWQ_units.hpp"
#include "openwq/src/utils/OpenWQ_utils.hpp"
#include "openwq/src/solver/OpenWQ_solver.hpp"
#include "openwq/src/output/OpenWQ_output.hpp"
#include <iostream>
#include <time.h>
#include <vector>

// Global Indexes for Compartments
  inline int rivernetwork_nRch_openwq = 0;
  //inline int canopy_index_openwq    = 0;
  //inline int snow_index_openwq      = 1;
  //inline int runoff_index_openwq    = 2;
  //inline int soil_index_openwq      = 3;
  //inline int aquifer_index_openwq   = 4;
  //inline int max_snow_layers        = 5;

// Global Indexes for EWF
  inline int summaEWF_runoff_openwq = 0;

class CLASSWQ_openwq
{

    // Instance Variables
    private:

        OpenWQ_couplercalls *OpenWQ_couplercalls_ref;
        OpenWQ_hostModelconfig *OpenWQ_hostModelconfig_ref;
        OpenWQ_json *OpenWQ_json_ref;
        OpenWQ_wqconfig *OpenWQ_wqconfig_ref;
        OpenWQ_units *OpenWQ_units_ref;
        OpenWQ_utils *OpenWQ_utils_ref;
        OpenWQ_readjson *OpenWQ_readjson_ref;
        OpenWQ_vars *OpenWQ_vars_ref;
        OpenWQ_initiate *OpenWQ_initiate_ref;
        OpenWQ_watertransp *OpenWQ_watertransp_ref;
        OpenWQ_chem *OpenWQ_chem_ref;            
        OpenWQ_extwatflux_ss *OpenWQ_extwatflux_ss_ref;
        OpenWQ_solver *OpenWQ_solver_ref;
        OpenWQ_output *OpenWQ_output_ref;

        int nRch;
        //const float *hru_area;

    // Constructor
    public:
        CLASSWQ_openwq();
        ~CLASSWQ_openwq();
    
    // Methods
    void printNum() {
        std::cout << "num = " << this->nRch << std::endl;
    }

    int decl(
        int nRch
        );           // num of layers in y-dir (set to 1 because not used in summa)

    int openwq_run_time_start(
        int simtime_mizuroute[],
        int nRch_2openwq,
        double REACH_VOL_0[]
        );

    int openwq_run_space(
        int simtime_summa[], 
        int source, int ix_s, int iy_s, int iz_s,
        int recipient, int ix_r, int iy_r, int iz_r, 
        double wflux_s2r, double wmass_source);

    int openwq_run_space_in(
        int simtime_summa[],
        std::string source_EWF_name,
        int recipient, int ix_r, int iy_r, int iz_r, 
        double wflux_s2r);

    int openwq_run_time_end(
        int simtime_summa[]);

};
#endif