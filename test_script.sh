# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_script.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabsanto <sabsanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/25 17:52:09 by sabsanto          #+#    #+#              #
#    Updated: 2025/03/25 17:52:23 by sabsanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

# Cores
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Testar todos os mapas
for map in maps/*.fdf; do
    echo -n "Testando $map... "
    ./fdf "$map" 2> /dev/null
    
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}✓ OK${NC}"
    else
        echo -e "${RED}✗ ERRO${NC}"
    fi
done

# Teste de valgrind (opcional)
echo -n "Verificando memory leaks... "
valgrind --leak-check=full --show-leak-kinds=all ./fdf maps/42.fdf 2>&1 | grep -q "ERROR SUMMARY: 0 errors"
if [ $? -eq 0 ]; then
    echo -e "${GREEN}✓ OK${NC}"
else
    echo -e "${RED}✗ VAZAMENTOS DETECTADOS${NC}"
fi