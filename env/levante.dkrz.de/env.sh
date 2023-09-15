export CPU_MODEL=AMD_EPYC_ZEN3

module load intel-oneapi-compilers/2022.0.1-gcc-11.2.0
module load intel-oneapi-mkl/2022.0.1-gcc-11.2.0
module load openmpi/4.1.2-intel-2021.5.0
module load netcdf-c/4.8.1-openmpi-4.1.2-intel-2021.5.0
module load netcdf-fortran/4.5.3-openmpi-4.1.2-intel-2021.5.0
module load hdf5/1.12.1-openmpi-4.1.2-intel-2021.5.0


export FC=mpif90 CC=mpicc CXX=mpicxx
export LD_LIBRARY_PATH=/sw/spack-levante/intel-oneapi-mkl-2022.0.1-ttdktf/mkl/2022.0.1/lib/intel64:$LD_LIBRARY_PATH

export NETCDF_C_INCLUDE_DIRECTORIES=/sw/spack-levante/netcdf-c-4.8.1-2k3cmu/include
export NETCDF_CXX_INCLUDE_DIRECTORIES=/sw/spack-levante/netcdf-cxx4-4.3.1-sbk7ks/include


