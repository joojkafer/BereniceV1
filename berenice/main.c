#include <stdio.h>
#include <stdlib.h>

int main(){

    int op, op2, op3, qprod;
    float vprod, vtot;
    float aux1, desconto;
    float vrtroco, vftroco;
    char continuar = 's';

    while(continuar == 's'){

        printf("Bem vindo ao Sistema da Berenice!\n\n");

        printf(" Item   | Nome do Item   | Valor\n");
        printf(" 1      | Pao de Forma   | R$ 7,50\n");
        printf(" 2      | Pao de Centeio | R$ 8,69\n");
        printf(" 3      | Broa de Milho  | R$ 5.00\n");
        printf(" 4      | Sonho          | R$ 4,50\n");
        printf(" 5      | Tubaina        | R$ 3,25\n");

        //ESCOLHA DO ITEM DA LISTA DE PRODUTOS
        do{
            printf("\nDigite o numero do item correspondente: ");
            scanf("%i", &op);
            getchar();

            if(op < 1 || op > 5){
                printf("Opcao invalida.\n");
            }
        }while(op < 1 || op > 5);

        switch (op){
            case 1:
                vprod = 7.50;
                printf("\nItem: Pao de Forma\nValor Unitario: R$ 7,50\n");
                break;
            case 2:
                vprod = 8.69;
                printf("\nItem: Pao de Centeio\nValor Unitario: R$ 8,69\n");
                break;
            case 3:
                vprod = 5.00;
                printf("\nItem: Broa de Milho\nValor Unitario: R$ 5,00\n");
                break;
            case 4:
                vprod = 4.50;
                printf("\nItem: Sonho\nValor Unitario: R$ 4,50\n");
                break;
            case 5:
                vprod = 3.25;
                printf("\nItem: Tubaina\nValor Unitario: R$ 3,25\n");
                break;
        }

        //INSERÇÃO DA QUANTIDADE DE ITENS QUE SERÃO COMPRADOS DO MESMO PRODUTO
        do{
            printf("\nDigite a quantidade que deseja comprar: ");
            scanf("%i", &qprod);
            getchar();
            if(qprod < 1){
                printf("Valor invalido.\n");
            }

        }while(qprod < 1);

        //CALCULO DO VALOR TOTAL DA COMPRA
        vtot = vprod * qprod;
        printf("\nValor total da compra: %.2f", vtot);

        //ESCOLHA DA FORMA DE PAGAMENTO
        printf("\n\nFormas de Pagamento: \n 1 - A vista e com desconto\n 2 - A prazo e com acrescimos\n");

        do{
            printf("\nEscolha a forma de pagamento: ");
            scanf("%i", &op2);
            getchar();

            if(op2 < 1 || op2 > 2){
                printf("Opcao invalida.\n");
            }
        }while(op2 < 1 || op2 > 2);

        //VERIFICAÇÃO DA FORMA DE PAGAMENTO (A VISTA)
        if(op2 == 1){
            //VERIFICAÇÃO DO VALOR DA COMPRA PARA APLICAR DESCONTO CORRETO
            if(vtot <= 50.00){
                //CALCULO DO DESCONTO PARA 5%
                aux1 = vtot / 100;
                desconto = aux1 * 5;
                printf("\nR$ %.2f de desconto.\n", desconto);

                vtot = vtot - desconto;
                printf("O valor final foi R$ %.2f.", vtot);
            }else if(vtot > 50 && vtot <= 99.99){
                //CALCULO DO DESCONTO PARA 10%
                aux1 = vtot / 100;
                desconto = aux1 * 10;
                printf("\nR$ %.2f de desconto.\n", desconto);

                vtot = vtot - desconto;
                printf("O valor final foi R$ %.2f.", vtot);
            }else{
                //CALCULO DO DESCONTO PARA 18%
                aux1 = vtot / 100;
                desconto = aux1 * 18;
                printf("\nR$ %.2f de desconto.\n", desconto);

                vtot = vtot - desconto;
                printf("O valor final foi R$ %.2f.", vtot);
            }

            //CALCULO DO TROCO
            printf("\n\nDigite qual o valor recebido para calculo do troco: ");
            scanf("%f", &vrtroco);
            getchar();

            //SE O VALOR DO TROCO FOR MENOR QUE O VALOR TOTAL, SERA EXIBIDO QUANTO FALTOU
            if(vrtroco < vtot){
                vftroco = vrtroco - vtot;
                vftroco = vftroco * -1;

                printf("\nValor insuficiente.\nFaltam R$ %.2f.\n", vftroco);
            //SE O VALOR DO TROCO FOR EXATAMENTE AO VALOR TOTAL, SERA EXIBIDO QUE NÃO HÁ TROCO
            }else if(vrtroco == vtot){
                printf("\nNao ha troco.\n");
            //SE O VALOR DO TROCO FOR MAIOR QUE O VALOR TOTAL, O TROCO SERA CALCULADO E EXIBIDO
            }else{
                vftroco = vrtroco - vtot;
                printf("\nO troco e R$ %.2f.\n", vftroco);
            }

            //VERIFICAÇÃO DA FORMA DE PAGAMENTO (A PRAZO)
            }else if(op2 == 2){
                //INSERÇÃO DO NUMERO DE PARCELAS QUE SERA FEITO
                do{
                    printf("\nDigite o numero de vezes que sera parcelado: ");
                    scanf("%i", &op3);
                    getchar();

                    if(op3 < 1){
                        printf("Valor invalido.\n");
                    }
                }while(op3 < 1);

                //VERIFICAÇÃO DO NUMERO DE PARCELAS DO PAGAMENTO A PRAZO
                if(op3 <= 3){
                    //CALCULO DO ACRESCIMO PARA 5%
                    aux1 = vtot / 100;
                    desconto = aux1 * 5;
                    printf("\nR$ %.2f de acrescimo.", desconto);

                    vtot = vtot + desconto;
                    printf("\nO valor final foi R$ %.2f.", vtot);
                }else{
                    //CALCULO DO ACRESCIMO PARA 8%
                    aux1 = vtot / 100;
                    desconto = aux1 * 8;
                    printf("\nR$ %.2f de acrescimo.", desconto);

                    vtot = vtot + desconto;
                    printf("\nO valor final foi R$ %.2f.", vtot);
                }
            //CASO A OPÇÃO DIGITADA SEJA INVALIDA
            }else{
                printf("Opcao invalida.\n");
            }

        printf("\nDeseja comprar mais algum produto?\n");
        printf(" S - Continuar\n\n ");
        scanf(" %c", &continuar);
        getchar();

        printf("\n");
    }

    return 0;
}
