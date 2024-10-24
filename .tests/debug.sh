#!/bin/bash

# Nom du fichier à modifier
file="/home/cauvray/projects/ft_printf/includes/ft_printf.h"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Vérifier si le fichier existe
if [[ ! -f "$file" ]]; then
    echo -e "${RED}Le fichier $file n'existe pas.${NC}"
    exit 1
fi

# Lire l'état actuel de DEBUG
current_debug=$(grep "^# *define *DEBUG" "$file" | awk '{print $4}')

if [[ "$current_debug" == "1" ]]; then
    # Si DEBUG est à 1, on le passe à 0
    sed -i 's/^# *define *DEBUG *1/#  define DEBUG 0/' "$file"
    echo -e "${RED}Debug Off${NC}"
elif [[ "$current_debug" == "0" ]]; then
    # Si DEBUG est à 0, on le passe à 1
    sed -i 's/^# *define *DEBUG *0/#  define DEBUG 1/' "$file"
    echo -e "${GREEN}Debug On${NC}"
else
    echo "${RED}DEBUG n'est ni défini à 1 ni à 0 dans $file.${NC}"
    exit 1
fi