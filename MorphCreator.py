import enum
from FBXReader import *

#write header
class MorphCreator:
    morphObj = MorphObject()
    
    def __init__(self, morphObj):
        self.morphObj = morphObj

    def GetHeader(self, name):
        return "#pragma once\n\n#include \"..\\Utils\\Morph.h\"\n#include \"..\\..\\..\\..\\Utils\\Math\\Rotation.h\"\n#include \"..\\..\\..\\..\\Scene\\Materials\\Static\\SimpleMaterial.h\"\n#include \"..\\..\\..\\..\\Scene\\Objects\\Object3D.h\"\n#include \"..\\..\\..\\..\\Renderer\\Utils\\IndexGroup.h\"\n\nclass " + name + "{\npublic:\n"

        #return "#pragma once\n\n#include \"..\Utils\Morph.h\"\n#include \"..\..\..\..\Utils\Math\Rotation.h\"\n#include \"..\..\..\..\Scene\Materials\Static\SimpleMaterial.h\"\n#include \"..\..\..\..\Scene\Objects\Object3D.h\"\n#include \"..\..\..\..\Renderer\Utils\IndexGroup.h\"\n\nclass " + name + "{\npublic:\n"
        #return "#pragma once\n\n#include \"Arduino.h\"\n#include \"..\Math\Rotation.h\"\n#include \"Morph.h\"\n#include \"..\Materials\SimpleMaterial.h\"\n#include \"..\Render\IndexGroup.h\"\n#include \"..\Render\Object3D.h\"\n\nclass " + name + "{\npublic:\n"

    def GetMorphEnums(self):
        enums = "\tenum Morphs {\n"
        for i, shapeKey in enumerate(self.morphObj.shapeKeys):
            if i in {len(self.morphObj.shapeKeys) - 1}:
                enums += "\t\t" + shapeKey.Name + "\n\t};\n\nprivate:\n"#last entry
            else:
                enums += "\t\t" + shapeKey.Name + ",\n"

        return enums

    def GetBasisVertices(self):
        basisVertices = "\tVector3D* basisVertices = new Vector3D[" + str(int(self.morphObj.baseMesh.VertexCount / 3)) + "] {"

        for i, vertex in enumerate(self.morphObj.baseMesh.Vertices):
            if i in {len(self.morphObj.baseMesh.Vertices) - 1}:
                basisVertices += "Vector3D(" + f'{vertex.X:.4f}' + "f," + f'{vertex.Y:.4f}' + "f," + f'{vertex.Z:.4f}' + "f)};\n" #last entry
            else:
                basisVertices += "Vector3D(" + f'{vertex.X:.4f}' + "f," + f'{vertex.Y:.4f}' + "f," + f'{vertex.Z:.4f}' + "f),"
                print(f'{vertex.X:.4f}' + "," + f'{vertex.Y:.4f}' + "," + f'{vertex.Z:.4f}'  + ",")

        return basisVertices

    def GetBasisIndexes(self):
        basisIndexes = "\tIndexGroup* basisIndexes = new IndexGroup[" + str(self.morphObj.baseMesh.TriangleCount) + "] {"

        for i, index in enumerate(self.morphObj.baseMesh.Triangles):
            if i in {len(self.morphObj.baseMesh.Triangles) - 1}:
                basisIndexes += "IndexGroup(" + str(index.A) + "," + str(index.B) + "," + str(index.C) + ")};\n"
            else:
                basisIndexes += "IndexGroup(" + str(index.A) + "," + str(index.B) + "," + str(index.C) + "),"

        return basisIndexes

    def GetBasisObject(self):
        lines =  "\tStaticTriangleGroup<" + str(int(self.morphObj.baseMesh.VertexCount / 3)) + "," + str(self.morphObj.baseMesh.TriangleCount) + "> triangleGroup = StaticTriangleGroup<" + str(int(self.morphObj.baseMesh.VertexCount / 3)) + "," + str(self.morphObj.baseMesh.TriangleCount) + ">(&basisVertices[0], &basisIndexes[0]);\n"
        lines += "\tTriangleGroup<" + str(int(self.morphObj.baseMesh.VertexCount / 3)) + "," + str(self.morphObj.baseMesh.TriangleCount) + "> triangleGroupMemory = TriangleGroup<" + str(int(self.morphObj.baseMesh.VertexCount / 3)) + "," + str(self.morphObj.baseMesh.TriangleCount) + ">(&triangleGroup);\n"
        lines += "\tSimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));\n"

        return lines + "\tObject3D basisObj = Object3D(&triangleGroup, &triangleGroupMemory, &simpleMaterial);\n\n"
        
    def GetMorphIndexes(self):
        morphIndexes = "\tstatic const uint8_t morphCount = " + str(len(self.morphObj.shapeKeys)) + ";\n"

        for shapeKey in self.morphObj.shapeKeys:
            morphIndexes += "\tint* " + shapeKey.Name + "Indexes = new int[" + str(shapeKey.IndexCount) + "] {"

            for i, index in enumerate(shapeKey.Indexes):
                if i in {len(shapeKey.Indexes) - 1}:
                    morphIndexes += str(index) + "};\n"
                else:
                    morphIndexes += str(index) + ","

        morphIndexes += "\n"

        return morphIndexes

    def GetMorphVectors(self):
        morphVectors = ""

        for shapeKey in self.morphObj.shapeKeys:
            morphVectors += "\tVector3D* " + shapeKey.Name + "Vectors = new Vector3D[" + str(int(shapeKey.VertexCount / 3)) + "] {"

            for i, vertex in enumerate(shapeKey.Vertices):
                if i in {len(shapeKey.Vertices) - 1}:
                    morphVectors += "Vector3D(" + f'{vertex.X:.4f}' + "f," + f'{vertex.Y:.4f}'+ "f," + f'{vertex.Z:.4f}' + "f)};\n"
                else:
                    morphVectors += "Vector3D(" + f'{vertex.X:.4f}' + "f," + f'{vertex.Y:.4f}' + "f," + f'{vertex.Z:.4f}' + "f),"

        morphVectors += "\n"

        return morphVectors

    def GetMorphObjects(self):
        morphObjects = "\tMorph morphs[" + str(len(self.morphObj.shapeKeys)) + "] = {\n"

        for i, shapeKey in enumerate(self.morphObj.shapeKeys):
            if i in {len(self.morphObj.shapeKeys) - 1}:
                morphObjects += "\t\tMorph(" + str(shapeKey.IndexCount) + ", " + shapeKey.Name + "Indexes, " + shapeKey.Name + "Vectors)\n\t};\n\n"
            else:
                morphObjects += "\t\tMorph(" + str(shapeKey.IndexCount) + ", " + shapeKey.Name + "Indexes, " + shapeKey.Name + "Vectors),\n"

        return morphObjects

    def GetRotationPositionOffset(self):
        #Quaternion rotation
        rotationPosition = "\tQuaternion offsetRotation = Rotation(EulerAngles(Vector3D("
        rotationPosition += f'{self.morphObj.baseMesh.ObjectParams.Rotation.X:.4f}' + "f," + f'{self.morphObj.baseMesh.ObjectParams.Rotation.Y:.4f}' + "f," + f'{self.morphObj.baseMesh.ObjectParams.Rotation.Z:.4f}'
        rotationPosition += "f), EulerConstants::EulerOrderXYZS)).GetQuaternion();\n"

        #Vector position
        rotationPosition += "\tVector3D offsetPosition = Vector3D("
        rotationPosition += f'{self.morphObj.baseMesh.ObjectParams.Position.X:.4f}' + "f," + f'{self.morphObj.baseMesh.ObjectParams.Position.Y:.4f}' + "f," + f'{self.morphObj.baseMesh.ObjectParams.Position.Z:.4f}'
        rotationPosition += "f);\n\n"

        return rotationPosition

    def GetPublicFunctions(self, name):
        publicFunctions = "public:\n"
        publicFunctions += "\t" + name + "(){}\n\n"
        publicFunctions += "\tObject3D* GetObject(){\n\t\treturn &basisObj;\n\t}\n\n"

        publicFunctions += "\tvoid SetMorphWeight(Morphs morph, float weight){\n"
        publicFunctions += "\t\tmorphs[morph].Weight = weight;\n\t}\n\n"

        publicFunctions += "\tfloat* GetMorphWeightReference(Morphs morph){\n"
        publicFunctions += "\t\treturn &morphs[morph].Weight;\n\t}\n\n"

        
        publicFunctions += "\tvoid Reset(){\n"
        publicFunctions += "\t\tfor(int i = 0; i < morphCount; i++){\n"
        publicFunctions += "\t\t\tmorphs[i].Weight = 0.0f;\n"
        publicFunctions += "\t\t}\n\t}\n\n"

        publicFunctions += "\tvoid Update(){\n"
        publicFunctions += "\t\tbasisObj.ResetVertices();\n\n"
        publicFunctions += "\t\tfor(int i = 0; i < morphCount; i++){\n"
        publicFunctions += "\t\t\tif(morphs[i].Weight > 0.0f){\n"
        publicFunctions += "\t\t\t\tmorphs[i].MorphObject3D(basisObj.GetTriangleGroup());\n"
        publicFunctions += "\t\t\t}\n"
        publicFunctions += "\t\t}\n\n"

        publicFunctions += "\t}\n};\n"

        return publicFunctions


    def GenerateMorphCode(self, name):
        morphCode = ""

        morphCode += self.GetHeader(name)
        morphCode += self.GetMorphEnums()
        morphCode += self.GetBasisVertices()
        morphCode += self.GetBasisIndexes()
        morphCode += self.GetBasisObject()
        morphCode += self.GetMorphIndexes()
        morphCode += self.GetMorphVectors()
        morphCode += self.GetMorphObjects()
        #morphCode += self.GetRotationPositionOffset()
        morphCode += self.GetPublicFunctions(name)

        return morphCode


