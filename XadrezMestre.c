#include <stdio.h>
#include <string.h>
//#include <windows.h>

// Função recursiva para mover todas as peças

void movePeca(char p, int quanto, int paraonde, char l, int n)
{
    // cacula e exibe os próximos movimentos até esgotar a qtde de casas que a peça deve se deslocar
    
    if (quanto > 0)
    {
        switch (p)
        {
            case 't':
            {
                switch (paraonde)
                {
                    case 1:
                        l--;
                        break;

                    case 2:
                        l++;
                        break;

                    case 3:
                        n++;
                        break;

                    case 4:
                        n--;
                        break;
                }

                break;
            }

            case 'b':
            {
                switch (paraonde)
                {
                    case 5:
                        l--;
                        n++;
                        break;

                    case 6:
                        l--;
                        n--;
                        break;

                    case 7:
                        l++;
                        n++;
                        break;

                    case 8:
                        l++;
                        n--;
                        break;
                }

                break;
            }

            case 'r':
            {
                switch (paraonde)
                {
                    case 1:
                        l--;
                        break;

                    case 2:
                        l++;
                        break;

                    case 3:
                        n++;
                        break;

                    case 4:
                        n--;
                        break;

                    case 5:
                        l--;
                        n++;
                        break;

                    case 6:
                        l--;
                        n--;
                        break;

                    case 7:
                        l++;
                        n++;
                        break;

                    case 8:
                        l++;
                        n--;
                        break;
                }

                break;
            }

            case 'c':
            {
                switch (paraonde)
                {
                    case 9:
                        quanto == 3 ? l-- : n++;
                        break;

                    case 10:
                        quanto == 3 ? l++ : n++;
                        break;

                    case 11:
                        quanto == 3 ? l-- : n--;
                        break;

                    case 12:
                        quanto == 3 ? l++ : n--;
                        break;

                    case 13:
                        quanto == 1 ? n++ : l--;
                        break;

                    case 14:
                        quanto == 1 ? n++ : l++;
                        break;

                    case 15:
                        quanto == 1 ? n-- : l--;
                        break;

                    case 16:
                        quanto == 1 ? n-- : l++;
                        break;
                }

                break;
            }
        }
// se extrapolou as dimensões do tabuleiro exibe msg de erro, senão exibe próximo movimento e aciona recursividade
        if (l < 'a' || l > 'h' || n < 1 || n > 8)
        {
            printf(" *Sua peça caiu do tabuleiro*\n");
        }
        else
        {
            printf(" -> %c%i", l, n);

            movePeca(p, quanto - 1, paraonde, l, n);
        }
    }
}


int main()
{
    //SetConsoleOutputCP(CP_UTF8);
    //SetConsoleCP(CP_UTF8);

    int num, casas, dir;           // número da casa, qtde de casas do movimento, direção do movimento
    int tudok = 0;                 // flag opções corretas
    char peca = ' ', letra, mais1; // peça, letra da casa, flag para continuar jogando
    char entrada[20];              // para usar o getchar

    // Exibe tabuleiro

    printf("\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("8 | a8 | b8 | c8 | d8 | e8 | f8 | g8 | h8 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("7 | a7 | b7 | c7 | d7 | e7 | f7 | g7 | h7 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("6 | a6 | b6 | c6 | d6 | e6 | f6 | g6 | h6 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("5 | a5 | b5 | c5 | d5 | e5 | f5 | g5 | h5 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("4 | a4 | b4 | c4 | d4 | e4 | f4 | g4 | h4 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("3 | a3 | b3 | c3 | d3 | e3 | f3 | g3 | h3 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("2 | a2 | b2 | c2 | d2 | e2 | f2 | g2 | h2 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("1 | a1 | b1 | c1 | d1 | e1 | f1 | g1 | h1 |\n");
    printf("  +----+----+----+----+----+----+----+----+\n");
    printf("    a    b    c    d    e    f    g    h   \n");

    // Loop principal - encerra ao ler opção mais1 != 's'

    do
    {
        printf("\n\n");

        // Lê e critica opções para o movimento

        do
        {
        printf("Escolha a peça a ser movida "
            "(t)orre (b)ispo (r)ainha (c)avalo: ");

        fgets(entrada, sizeof(entrada), stdin);

        peca = entrada[0];

        if (peca != 't' && peca != 'b' &&
            peca != 'r' && peca != 'c')
        {
        printf("*Peça inválida*\n\n");
        }

        } while (peca != 't' && peca != 'b' &&
                 peca != 'r' && peca != 'c');

        printf("\n");

        do
        {
            printf("Escolha a casa de partida da peça: ");
            fgets(entrada, sizeof(entrada), stdin);

            letra = entrada[0];
            num = entrada[1] - '0';

            if ((letra < 'a' || letra > 'h') ||
                (num < 1 || num > 8))
            {
                printf("*Casa de partida inválida*\n\n");
            }

        } while ((letra < 'a' || letra > 'h') ||
                 (num < 1 || num > 8));

        printf("\n");

        do
        {
            if (peca != 'c')
            {
                printf("Escolha a quantidade de casas que peça deve andar (1 a 7): ");
                fgets(entrada, sizeof(entrada), stdin);

                if (sscanf(entrada, "%d", &casas) != 1)
                {
                    printf("*Digite um número válido*\n\n");
                    casas = 0;
                }
                else if (casas < 1 || casas > 7)
                {
                    printf("*Quantidade de casas inválida*\n\n");
                }
            }
            else
            {
                casas = 3;
            }

        } while (casas < 1 || casas > 7);

        printf("\n");

        while (tudok == 0)
{
    // lê opção de movimento

            printf("1.  horizontal esquerda\n");
            printf("2.  horizontal direita\n");
            printf("3.  vertical acima\n");
            printf("4.  vertical abaixo\n");
            printf("5.  diagonal esquerda acima\n");
            printf("6.  diagonal esquerda abaixo\n");
            printf("7.  diagonal direita acima\n");
            printf("8.  diagonal direita abaixo\n");
            printf("9.  L 2 acima 1 esquerda\n");
            printf("10. L 2 acima 1 direita\n");
            printf("11. L 2 abaixo 1 esquerda\n");
            printf("12. L 2 abaixo 1 direita\n");
            printf("13. L 1 acima 2 esquerda\n");
            printf("14. L 1 acima 2 direita\n");
            printf("15. L 1 abaixo 2 esquerda\n");
            printf("16. L 1 abaixo 2 direita\n");

            printf("Escolha a direção que a peça deve andar: ");

    if (scanf(" %d", &dir) != 1)
    {
        printf("*Digite um número entre 1 e 16*\n\n");

        while (getchar() != '\n');

        continue;
    }

    if (dir < 1 || dir > 16)
    {
        printf("*Direção inválida*\n\n");
    }
    else if ((dir >= 5 && dir <= 8) && peca == 't')
    {
        printf("*A torre não anda em diagonal*\n\n");
    }
    else if ((dir >= 1 && dir <= 4) && peca == 'b')
    {
        printf("*O bispo só anda em diagonal*\n\n");
    }
    else if ((dir >= 9 && dir <= 16) && peca != 'c')
    {
        printf("*Somente o cavalo anda em L*\n\n");
    }
    else if ((dir >= 1 && dir <= 8) && peca == 'c')
    {
        printf("*O cavalo anda somente em L*\n\n");
    }
    else
    {
        tudok = 1;
    }
}

        // Exibe a casa inicial

        printf("\n");
        printf("%c%i", letra, num);

        // Calcula e exibe os próximos movimentos

        switch (peca)
        {
            case 'c':
                casas = 3;
            default:
                movePeca(peca, casas, dir, letra, num);
                break;
        }

        printf("\n\n");
        while (getchar() != '\n');
        printf("Quer fazer outro movimento? (s)im ou (n)ão : ");
        do {
        fgets(entrada, sizeof(entrada), stdin);
        mais1 = entrada[0];
        if (mais1 != 's' && mais1 != 'n')
                {
                    printf("*Digite s ou n*\n");
                }
        } while (mais1 != 's' && mais1 != 'n');
        
        tudok = 0;

    } while (mais1 == 's');

    printf("Saindo...\n");

    return 0;
}