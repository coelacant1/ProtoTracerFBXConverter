# ONLY ONE MODEL
# ONE POSE MORPH mesh with sub shapes
# MUST BE TRIANGULATED MODEL
# Assume 100% weight on each shape key
# input in meters, output in mm
from FBXReader import *
from MorphCreator import *


#convert binary fbx to ascii
def BinaryToAscii(filename):
    print("Converting Binary FBX to Ascii FBX...")



    print("Ascii FBX created and saved.")
    #
    #append _ascii

with open('Example Files\KaiborgFaceMorphAscii.fbx', 'r') as file:
    data = file.read()

    name = "KaiborgV1"
    morphCreator = MorphCreator(GetMorphObject(data, name, 10.0)) #default is centimeters, prototracer uses millimeters

    morphCodeString = morphCreator.GenerateMorphCode(name).expandtabs(4)

    print(morphCodeString)
    