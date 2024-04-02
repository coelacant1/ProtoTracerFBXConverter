# ONLY ONE MODEL
# ONE POSE MORPH mesh with sub shapes
# MUST BE TRIANGULATED MODEL
# Assume 100% weight on each shape key
# input in meters, output in mm
from FBXReader import *
from MorphCreator import *
import os

name = "UnicornZhenja"
origFileName = f"Commissions\{name}.fbx"
newFileName = f"Output\{name}Ascii.fbx"
outputName = f"..\ProtoTracer\lib\ProtoTracer\Assets\Models\FBX\Commissions\{name}.h"

os.system("FbXFormatConverter.exe -c \"" + origFileName + "\" -o \"" + newFileName + "\" -ascii")

with open(newFileName, 'r') as file:
    data = file.read()

    morphCreator = MorphCreator(GetMorphObject(data, name, 10.0)) #default is centimeters, prototracer uses millimeters

    morphCodeString = morphCreator.GenerateMorphCode(name).expandtabs(4)

    #print(morphCodeString)
    f = open(outputName, "w")
    f.write(morphCodeString)
    f.close()
    