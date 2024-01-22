#include <string>

#define MAX_CONST_ZA_SIZE 200

const string regZAU = "(?<type>ZAU) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<constructible>[0-9]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
const string regZU = "(?<type>ZU) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<constructible>[0-9]+) (?<tible>[0-9]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
const string regZA = "(?<type>ZA) (?<number>[0-9]+) (?<proprietaire>[\w']+) (?<culture>[\wéï]+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";
const string regZN = "(?<type>ZN) (?<number>[0-9]+) (?<proprietaire>[\w']+)\n(?<polygone>\[[[\d\W ]+\])[\n]?";

const string regPoint = "(?<point>\[[-]?[0-9]+;[-]?[0-9]+\])";