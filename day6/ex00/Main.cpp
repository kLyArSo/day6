#include <iostream>
#include <string>
int    set_x(const char  **argv, std::string arg)
{
    int x;
    if (arg[0] >= '0' && arg[0] <= '9')
        x = atoi(argv[1]);
    else
        x = argv[1][0];
    return (x);
}

int     check(std::string input)
{
    if (input == "nan" || input == "nanf")
        return (0);
    if (input == "+inf" || input == "+inff")
        return (1);
    if (input == "-inf"|| input == "-inff")
        return (2);
    return (-1);
}

int main(int argc, const char  **argv)
{
    int x;
    if (argc == 2)
    {
        std::string arg = argv[1];
        if (arg.length() == 1 || arg.length() == 0)
        {
            x = set_x(argv, arg);
            if (isprint(x) == 0)//not print
                std::cout << "Char : Non Displayable" << std::endl;
            else
                std::cout << "Char : '" << (char)x << "'" << std::endl;
            std::cout << "Int : " << (int)x<< std::endl;
            std::cout << "Float : " << (float)x << ".0f" << std::endl;
            std::cout << "Double : " << (double)x << ".0" << std::endl;
        }
        else if ((x = check(arg)) != -1)
        {
            std::cout << "Char : Impossible" << std::endl;
            std::cout << "Int  : Impossible" << std::endl;
            if (x == 0)
            {
                std::cout << "Float :  nanf" << std::endl;
                std::cout << "Double : nan" << std::endl;
            }
            else if (x == 1)
            {
                std::cout << "Float : +inff" << std::endl;
                std::cout << "Double : +inf" << std::endl;
            }
            else if (x == 2)
            {
                std::cout << "Float : -inff" << std::endl;
                std::cout << "Double : -inf" << std::endl;
            }
        }
        else
        {
            try
            {
                x = atoi(argv[1]);
                int i_n_t = x;
                char c_h_a_r = x;
                float f_l_o_a_t = stof(arg);
                double d_o_u_b_l_e = stod(arg);
                if (isprint(x) == 0)
                    std::cout << "Char : Non Displayable!" << std::endl;
                else
                    std::cout << "Char : '" << c_h_a_r << "'" << std::endl;
                std::cout << "Int : " << i_n_t << std::endl;
                std::cout << "Float : " << f_l_o_a_t ;
                std::cout << ((f_l_o_a_t - (int)f_l_o_a_t == 0.0) ? ".0f" : "f");
                std::cout << std::endl;
                std::cout << "Double : " << d_o_u_b_l_e;
                std::cout << ((d_o_u_b_l_e - (int)d_o_u_b_l_e == 0.0) ? ".0" : "");
                std::cout << std::endl;
            }
            catch(std::exception &e)
            {
                (void)e;
                std::cout << "ERROR\n";
            }
        }
    }
    else
        std::cout << "ERROR NUMBER OF ARGS" << std::endl;
}