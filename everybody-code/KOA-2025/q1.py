res2 = [
    "Tharndaros", "Jaerdravor", "Elvaridris", "Cragaris", "Dorzor", "Arakhynd",
    "Galkryth", "Hazdax", "Ryssfarin", "Qyranixis", "Morfal", "Drelketh",
    "Pylarlar", "Kazzyth", "Paldaris", "Kronrax", "Rahnylor", "Vornzris",
    "Silardith", "Rythloris", "Irynulth", "Vancarth", "Dalverax", "Falaelor",
    "Balor", "Urzor", "Agnarmal", "Elarxal", "Glynnloris", "Caeljorath"
]
length = len(res2)
instructions = (
    -37, 28, -30, 13, -43, 47, -33, 5, -20, 8, -29, 36, -32, 49, -29, 31, -17, 37, -42, 35,
    -5, 33, -5, 47, -5, 38, -5, 7, -5, 34, -5, 47, -5, 24, -5, 17, -5, 40, -5, 10,
    -19, 31, -47, 31, -42, 16, -41, 29, -42, 17, -46, 40, -6, 15, -10, 15, -49, 22, -35
)

for i in range(len(instructions)):
		res2[instructions[i] % length],res2[0] = res2[0],res2[instructions[i] % length]

print(res2[0])