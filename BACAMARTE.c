/*
 * ============================================================
 *   BACAMARTE: CRÔNICAS DO SERTÃO
 *   RPG Desenvolvido em Linguagem C
 * ------------------------------------------------------------
 *   Temática: Nordeste brasileiro, cangaceiros, caatinga.
 *   Mecânicas: combate por turnos, exploração de 5 regiões,
 *              itens, chefe final (Lampião), sistema de XP e nível.
 *   Restrições: sem vetores, matrizes, funções ou procedimentos.
 *   Recursos obrigatórios: random, for e/ou while.
 * ============================================================
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
 
int main() {

    setlocale(LC_ALL, "Portuguese_Brazil.UTF-8");
 
    /* ── Semente para números aleatórios ── */
    srand(time(NULL));
 
    /* ══════════════════════════════════════
       ATRIBUTOS DO HERÓI (Cangaceiro Novato)
       ══════════════════════════════════════ */
    int heroi_vida      = 100;  /* Pontos de vida atuais                  */
    int heroi_vida_max  = 100;  /* Pontos de vida máximos                 */
    int heroi_ataque    = 15;   /* Dano base (faca, bacamarte, etc.)      */
    int heroi_defesa    = 5;    /* Redução de dano recebido               */
    int heroi_nivel     = 1;    /* Nível atual do cangaceiro              */
    int heroi_xp        = 0;    /* Experiência acumulada                  */
    int heroi_xp_prox   = 30;   /* XP necessária para próximo nível       */
    int heroi_moeda     = 10;   /* Patacas (moeda do sertão)              */
    int heroi_garapa    = 2;    /* Garrafas de garapa (cura)              */
 
    /* ── Flags de progressão ── */
    int regiao_atual      = 1;  /* Região atual (1-5)                     */
    int jogo_rodando      = 1;  /* Controla o loop principal              */
 
    /* ── Variáveis de combate / auxiliares ── */
    int inimigo_vida, inimigo_ataque, inimigo_defesa;
    int dano, dado, escolha;
    int recompensa_xp, recompensa_patacas;
 
    /* ══════════════════════════════════════
       APRESENTAÇÃO
       ══════════════════════════════════════ */
    printf("\n");
    printf("  ╔══════════════════════════════════════════════════╗\n");
    printf("  ║   ██████   █████   ██████  █████  ███╗           ║\n");
    printf("  ║   ██   ██ ██   ██ ██      ██   ██ ████╗          ║\n");
    printf("  ║   ██████  ███████ ██      ███████ ██╔██╗         ║\n");
    printf("  ║   ██   ██ ██   ██ ██      ██   ██ ██║╚██╗        ║\n");
    printf("  ║   ██████  ██   ██  ██████ ██   ██ ██║ ╚██╗       ║\n");
    printf("  ╠══════════════════════════════════════════════════╣\n");
    printf("  ║       🌵  CRÔNICAS DO SERTÃO  🌵                  ║\n");
    printf("  ║        RPG Desenvolvido em Linguagem C            ║\n");
    printf("  ╚══════════════════════════════════════════════════╝\n\n");
    printf("  Você é um cangaceiro novato que adentrou o sertão\n");
    printf("  bravo do Nordeste em busca de honra e liberdade.\n");
    printf("  Cinco regiões separam você do lendário LAMPIÃO!\n\n");
    printf("  Pressione ENTER para começar sua jornada...\n");
    getchar();
 
    /* ══════════════════════════════════════
       LOOP PRINCIPAL DO JOGO
       ══════════════════════════════════════ */
    while (jogo_rodando) {
 
        /* ── Verifica morte do herói ── */
        if (heroi_vida <= 0) {
            printf("\n  ☠  Você caiu no sertão e a caatinga te engoliu...\n");
            printf("  Os urubus já estão circulando. FIM DE JOGO!\n\n");
            jogo_rodando = 0;
            break;
        }
 
        /* ── Verifica vitória ── */
        if (regiao_atual > 5) {
            printf("\n  🏆 VOCÊ DERROTOU LAMPIÃO E VIROU LENDA DO SERTÃO!\n");
            printf("  Seu nome vai ser cantado pelos repentistas por gerações!\n");
            printf("  Nível final: %d  |  Patacas: %d\n\n",
                   heroi_nivel, heroi_moeda);
            jogo_rodando = 0;
            break;
        }
 
        /* ── Cabeçalho de status ── */
        printf("\n  ════════════════════════════════════════════\n");
        printf("  📍 REGIÃO %d de 5", regiao_atual);
        if (regiao_atual == 5) printf("  [COVIL DE LAMPIÃO]");
        printf("\n");
        printf("  ❤  Vida: %d/%d  |  ⭐ Nível: %d  |  ✨ XP: %d/%d\n",
               heroi_vida, heroi_vida_max, heroi_nivel, heroi_xp, heroi_xp_prox);
        printf("  🔫 Ataque: %d  |  🧣 Defesa: %d  |  💰 Patacas: %d  |  🍶 Garapa: %d\n",
               heroi_ataque, heroi_defesa, heroi_moeda, heroi_garapa);
        printf("  ════════════════════════════════════════════\n\n");
 
        /* ══════════════════════════════════════
           DEFINIÇÃO DO INIMIGO DA REGIÃO
           ══════════════════════════════════════ */
        if (regiao_atual == 1) {
            printf("  🐍 Um CAPANGA DE ESTRADA surge da macambira com uma faca!\n");
            printf("  \"Passa o dinheiro ou passa mal!\"\n");
            inimigo_vida    = 30;
            inimigo_ataque  = 8;
            inimigo_defesa  = 2;
            recompensa_xp   = 15;
            recompensa_patacas = 5 + rand() % 6;   /* 5-10 patacas */
        } else if (regiao_atual == 2) {
            printf("  🤠 Um CORONEL SAFADO manda seus jagunços te cercar!\n");
            printf("  \"Cangaceiro vagabundo, sai da minha terra!\"\n");
            inimigo_vida    = 50;
            inimigo_ataque  = 12;
            inimigo_defesa  = 3;
            recompensa_xp   = 25;
            recompensa_patacas = 8 + rand() % 8;   /* 8-15 patacas */
        } else if (regiao_atual == 3) {
            printf("  👮 Um TENENTE DA VOLANTE avança com o rifle engatilhado!\n");
            printf("  \"Entrega os cangaceiros, cabra danado!\"\n");
            inimigo_vida    = 70;
            inimigo_ataque  = 16;
            inimigo_defesa  = 6;
            recompensa_xp   = 40;
            recompensa_patacas = 12 + rand() % 9;  /* 12-20 patacas */
        } else if (regiao_atual == 4) {
            printf("  🦅 O CANGACEIRO CORISCO te desafia numa clareira de xique-xique!\n");
            printf("  \"Só um de nós sai daqui de pé, cabra!\"\n");
            inimigo_vida    = 90;
            inimigo_ataque  = 22;
            inimigo_defesa  = 4;
            recompensa_xp   = 55;
            recompensa_patacas = 20 + rand() % 11; /* 20-30 patacas */
        } else {
            /* Região 5 — Chefe Final */
            printf("  🔥💀 LAMPIÃO aparece com o chapéu de couro e o bacamarte!\n");
            printf("  \"Oxente! Achou que ia chegar até mim, menino?\"\n");
            printf("  O rei do cangaço te mira com os olhos de fogo...\n");
            inimigo_vida    = 200;
            inimigo_ataque  = 30;
            inimigo_defesa  = 10;
            recompensa_xp   = 0;
            recompensa_patacas = 100;
        }
 
        printf("\n  O inimigo tem %d pontos de vida!\n", inimigo_vida);
 
        /* ══════════════════════════════════════
           LOOP DE COMBATE
           ══════════════════════════════════════ */
        while (inimigo_vida > 0 && heroi_vida > 0) {
 
            printf("\n  ── O QUE VOCÊ FAZ? ──────────────────────────\n");
            printf("  [1] Atacar           [2] Tomar Garapa (%d)\n", heroi_garapa);
            printf("  [3] Se agachar (+5 defesa este turno)\n");
            printf("  Escolha: ");
            scanf("%d", &escolha);
            while (getchar() != '\n');
 
            /* ── Turno do Herói ── */
            if (escolha == 1) {
                /* Dado de 1-10 somado ao ataque base */
                dado = 1 + rand() % 10;
                dano = heroi_ataque + dado - inimigo_defesa;
                if (dano < 1) dano = 1;
 
                /* Crítico: dado == 10 dobra o dano (tiro certeiro) */
                if (dado == 10) {
                    dano *= 2;
                    printf("\n  💥 TIRO CERTEIRO! O bacamarte trovejou no sertão!\n");
                } else {
                    printf("\n  🔫 Você atacou e causou %d de dano!\n", dano);
                }
                inimigo_vida -= dano;
 
            } else if (escolha == 2) {
                if (heroi_garapa > 0) {
                    int cura = 25 + rand() % 16; /* Cura 25-40 HP */
                    heroi_vida += cura;
                    if (heroi_vida > heroi_vida_max) heroi_vida = heroi_vida_max;
                    heroi_garapa--;
                    printf("\n  🍶 Você tomou uma garapa bem gelada e recuperou %d de vida!\n",
                           cura);
                    printf("  Vida atual: %d/%d\n", heroi_vida, heroi_vida_max);
                } else {
                    printf("\n  ❌ Sem garapa! Você tremeu e perdeu o turno, cabra!\n");
                }
                dano = 0;
 
            } else if (escolha == 3) {
                heroi_defesa += 5;
                printf("\n  🧣 Você se agachou atrás de um umbuzeiro! Defesa +5 neste turno.\n");
                dano = 0;
 
            } else {
                printf("\n  ❓ Ficou parado feito um jumento! Perdeu o turno.\n");
                dano = 0;
            }
 
            /* Inimigo ainda vivo? Contra-ataca */
            if (inimigo_vida > 0) {
                dado = 1 + rand() % 8;
                dano = inimigo_ataque + dado - heroi_defesa;
                if (dano < 1) dano = 1;
 
                /* 20% de chance de ataque especial */
                if ((rand() % 5) == 0) {
                    dano = (int)(dano * 1.5);
                    printf("  🔥 Ataque covarde do inimigo! ");
                } else {
                    printf("  👊 O inimigo reagiu! ");
                }
                printf("Você sofreu %d de dano.\n", dano);
                heroi_vida -= dano;
 
                if (heroi_vida < 0) heroi_vida = 0;
                printf("  ❤  Vida restante: %d/%d\n", heroi_vida, heroi_vida_max);
            }
 
            /* Remove bônus de defesa temporária */
            if (escolha == 3) heroi_defesa -= 5;
 
            /* Mostra vida do inimigo */
            if (inimigo_vida > 0)
                printf("  👹 Vida do inimigo: %d\n", inimigo_vida);
        }
 
        /* ══════════════════════════════════════
           RESOLUÇÃO APÓS COMBATE
           ══════════════════════════════════════ */
        if (heroi_vida <= 0) {
            continue; /* Tratado no topo do loop */
        }
 
        /* Inimigo derrotado! */
        printf("\n  ✅ Inimigo nocauteado no sertão!\n");
        printf("  +%d XP  |  +%d Patacas\n", recompensa_xp, recompensa_patacas);
        heroi_xp    += recompensa_xp;
        heroi_moeda += recompensa_patacas;
 
        /* ── Verificação de nível ── */
        while (heroi_xp >= heroi_xp_prox) {
            heroi_xp      -= heroi_xp_prox;
            heroi_nivel++;
            heroi_xp_prox  = heroi_nivel * 30;
            heroi_ataque  += 3;
            heroi_defesa  += 1;
            heroi_vida_max += 15;
            heroi_vida    += 15;
            if (heroi_vida > heroi_vida_max) heroi_vida = heroi_vida_max;
 
            printf("\n  🌟 FICOU MAIS DANADO! Agora é nível %d!\n", heroi_nivel);
            printf("  🔫 Ataque: %d  |  🧣 Defesa: %d  |  ❤  Vida máx: %d\n",
                   heroi_ataque, heroi_defesa, heroi_vida_max);
        }
 
        /* ── Evento aleatório ao avançar pela caatinga ── */
        dado = rand() % 3;
        if (dado == 0) {
            printf("\n  🌵 Atrás de um mandacaru você achou uma garafa de garapa!\n");
            heroi_garapa++;
        } else if (dado == 1) {
            int bonus = 3 + rand() % 8;
            printf("\n  💰 Você encontrou um alforje abandonado com %d patacas!\n", bonus);
            heroi_moeda += bonus;
        } else {
            printf("\n  🦎 O lagarto te olhou feio e correu. O sertão tá quieto...\n");
        }
 
        /* ── Feira do sertão (a cada 2 regiões) ── */
        if (regiao_atual == 2 || regiao_atual == 4) {
            printf("\n  🏪 Um mascate aparece com o burro carregado de bugigangas!\n");
            printf("  Suas patacas: %d\n\n", heroi_moeda);
            printf("  [1] Garapa de umbu     (15 patacas)\n");
            printf("  [2] Afiar o facão      (+3 ataque, 20 patacas)\n");
            printf("  [3] Couro de bode      (+2 defesa, 18 patacas)\n");
            printf("  [4] Seguir viagem\n");
            printf("  Escolha: ");
            scanf("%d", &escolha);
            while (getchar() != '\n');
 
            if (escolha == 1 && heroi_moeda >= 15) {
                heroi_moeda -= 15;
                heroi_garapa++;
                printf("  🍶 Garapa comprada! Garapas: %d\n", heroi_garapa);
            } else if (escolha == 2 && heroi_moeda >= 20) {
                heroi_moeda -= 20;
                heroi_ataque += 3;
                printf("  🔪 Facão afiado! Ataque: %d\n", heroi_ataque);
            } else if (escolha == 3 && heroi_moeda >= 18) {
                heroi_moeda -= 18;
                heroi_defesa += 2;
                printf("  🧣 Couro de bode vestido! Defesa: %d\n", heroi_defesa);
            } else if (escolha != 4) {
                printf("  ❌ Patacas insuficientes ou opção inválida, véi.\n");
            }
        }
 
        /* ── Avança para a próxima região ── */
        regiao_atual++;
 
        if (regiao_atual <= 5) {
            printf("\n  ➡  Você segue pela caatinga em direção à Região %d...\n",
                   regiao_atual);
            printf("  Pressione ENTER para continuar a jornada.\n");
            getchar();
        }
 
    } /* fim do while principal */
 
    /* ══════════════════════════════════════
       CRÉDITOS FINAIS
       ══════════════════════════════════════ */
    printf("\n  ══════════════════════════════════════════════════\n");
    printf("  Obrigado por jogar BACAMARTE: CRÔNICAS DO SERTÃO!\n");
    printf("  RPG Desenvolvido em Linguagem C  🎓\n");
    printf("  \"O sertão vai virar mar e o mar vai virar sertão.\"\n");
    printf("  ══════════════════════════════════════════════════\n\n");
 
    return 0;
}