mkdir build
cd build
cp -f ../in ./
cmake -GNinja ../
ninja && ./dfs_parallel < in
