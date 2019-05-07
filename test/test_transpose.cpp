#include "gtest/gtest.h"
#include <stdlib.h>
#include <netcdf>
#include <chrono>

#include "globals.h"
#include "transpose.h"

using namespace std;
using namespace netCDF;
using namespace ncn;


namespace {

   
   TEST(ncn_rowcol, can_read)
   {
      string inpath = fixture_dir+"/transpose.nc";
      string outpath = "./transpose.nc.2A1F0DB9_BA11_4321_8666_1A232DEC6B30";

      ncn::transpose_netcdf_dimensions(inpath, outpath, "temp", {"nod2", "nz1"}); // time, nod2, nz1 => time, nz1, nod2

      NcFile ncf(outpath, NcFile::read);
      NcVar var = ncf.getVar("temp");
      EXPECT_EQ(3, var.getDimCount());
      vector<float> data(var.getDim(0).getSize() * var.getDim(1).getSize() * var.getDim(2).getSize());
      var.getVar(&data[0]);
      
      vector<double> exp_data = {-1.00099F, -1.03099F, -1.06099F, -1.09099F, -1.12099F, -1.01099F, -1.04099F, -1.07099F, -1.10099F, -1.13099F, -1.02099F, -1.05099F, -1.08099F, -1.11099F, -1.1499F, -2.00099F, -2.03099F, -2.06099F, -2.09099F, -2.12099F, -2.01099F, -2.04099F, -2.07099F, -2.10099F, -2.13099F, -2.02099F, -2.05099F, -2.08099F, -2.11099F, -2.1499F};
      EXPECT_EQ(exp_data.size(), data.size());
      for(int i = 0; i < exp_data.size(); i++)
      {
         EXPECT_FLOAT_EQ(exp_data[i], data[i]);
      }

      string cmd = "rm "+outpath;
      system(cmd.c_str());
   }

}  // namespace
