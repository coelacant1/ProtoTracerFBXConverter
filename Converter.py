# ONLY ONE MODEL
# ONE POSE MORPH mesh with sub shapes
# MUST BE TRIANGULATED MODEL
# Assume 100% weight on each shape key
from FBXReader import *

#convert binary fbx to ascii
def BinaryToAscii(filename):
    print("Converting Binary FBX to Ascii FBX...")

    

    print("Ascii FBX created and saved.")
    #
    #append _ascii

with open('Example Files\KaiborgFaceMorphAscii.fbx', 'r') as file:
    data = file.read()

    GetMorphObject(data)