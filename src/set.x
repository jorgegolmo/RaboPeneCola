
struct Coord{
 int x;
 int y;
};

typedef double doubles_array<>;

program TUPLAS {
    version PRUEBA {
        int set_value_rpc(int key, string value1<>, int N_value2, doubles_array V_value2, struct Coord value3) = 1;
        int exist_rpc (int key) = 2;
        } = 1;
} = 11710;