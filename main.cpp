#include <iostream>
#include <vector>

using namespace std;

enum Shape : int
{
    ArrowOutPlug = 00,
    ArrowOutHole = 01,   // 1

    ArrowInPlug = 10,    // 2
    ArrowInHole = 11,    // 3

    CrossPlug = 20,      // 4
    CrossHole = 21,      // 5

    CirclePlug = 30,     // 6
    CircleHole = 31,     // 7

    ERROR = 40        //8
};

struct Piece
{
    Shape up;
    Shape right;
    Shape down;
    Shape left;

    int rotation;

    //Shape getUp();
    //Shape getRight();
    //Shape getDown();
    //Shape getLeft();

    Shape getUp(int rot);
    Shape getRight(int rot);
    Shape getDown(int rot);
    Shape getLeft(int rot);
};

struct TwoByTwoSet
{
    Piece pTL;
    Piece pTR;
    Piece pBL;
    Piece pBR;
};

struct TwoByTwoIndex
{
    int TLIndex;
    int TLRot;

    int TRIndex;
    int TRRot;

    int BLIndex;
    int BLRot;

    int BRIndex;
    int BRRot;
};

struct ThreeByThreeIndex
{
    TwoByTwoIndex* Topleft;

    int Index0;
    int Rot0;

    int Index1;
    int Rot1;

    int Index2;
    int Rot2;

    int Index3;
    int Rot3;

    int Index4;
    int Rot4;


    ThreeByThreeIndex(TwoByTwoIndex* tl, int i0, int r0, int i1, int r1, int i2, int r2, int i3, int r3, int i4, int r4) :
        Topleft(tl),
        Index0(i0),
        Rot0(r0),
        Index1(i1),
        Rot1(r1),
        Index2(i2),
        Rot2(r2),
        Index3(i3),
        Rot3(r3),
        Index4(i4),
        Rot4(r4)
    {

    };


    //~ThreeByThreeIndex() { if (Topleft) { delete Topleft; } }

};




//struct Solution
//{
//    TwoByTwoIndex TopLeft;
//    TwoByTwoIndex TopRight;
//    TwoByTwoIndex BottomLeft;
//    TwoByTwoIndex BottomRight;
//};

struct SolutionIndex
{
    int index0;
    int rot0;

    int index1;
    int rot1;

    int index2;
    int rot2;

    int index3;
    int rot3;

    int index4;
    int rot4;

    int index5;
    int rot5;

    int index6;
    int rot6;

    int index7;
    int rot7;

    int index8;
    int rot8;

    int index9;
    int rot9;

    int index10;
    int rot10;

    int index11;
    int rot11;

    int index12;
    int rot12;

    int index13;
    int rot13;

    int index14;
    int rot14;

    int index15;
    int rot15;
};


bool checkTwoByTwo(Piece tl, Piece tr, Piece bl, Piece br);

bool checkWholeByTwoByTwo(TwoByTwoIndex TL, TwoByTwoIndex TR, TwoByTwoIndex BL, TwoByTwoIndex BR/*, Piece pieces[]*/);

bool checkFit(Shape a, Shape b);

void doSpins(Piece tl, Piece tr, Piece bl, Piece br);

bool compareIndexToThrees(int index, ThreeByThreeIndex three);// returns is unique

int main()
{
    // coding began: 6:30 AM, Sun April 20th, 2025
    // found 3 solutions 12:19 AM, same day

    int rotations = 4;

    int setIndex = 0;

    int solutionIndex = 0;

    int threesIndex = 0;
    int threesIndex2 = 0;

    //TwoByTwoSet sets[2000];
    TwoByTwoIndex twos[3500];

    int yeah = 20010;

    ThreeByThreeIndex* threes[20010];
    //ThreeByThreeIndex threes2[1000];

    std::vector<SolutionIndex> solutions;

    //SolutionIndex solutions[50];


    Piece pieces[16];

    pieces[0] = { ArrowOutHole, CrossPlug, ArrowInPlug, ArrowInHole, 0 };
    pieces[1] = { ArrowOutHole, CirclePlug, ArrowInPlug, ArrowInHole, 0 };
    pieces[2] = { ArrowOutHole, ArrowOutPlug, ArrowInPlug, CircleHole, 0 };
    pieces[3] = { CircleHole, CrossPlug, ArrowOutPlug, ArrowOutHole, 0 };
    pieces[4] = { CrossHole, ArrowInPlug, CirclePlug, ArrowInHole, 0 };
    pieces[5] = { CircleHole, CirclePlug, ArrowOutPlug, CrossHole, 0 };
    pieces[6] = { CircleHole, ArrowOutPlug, ArrowOutPlug, ArrowInHole, 0 };
    pieces[7] = { CircleHole, CirclePlug, ArrowOutPlug, ArrowOutHole, 0 };
    pieces[8] = { CircleHole, CirclePlug, CirclePlug, ArrowOutHole, 0 };
    pieces[9] = { ArrowOutHole, ArrowInPlug, ArrowInPlug, CrossHole, 0 };
    pieces[10] = { CircleHole, CirclePlug, CrossPlug, CrossHole, 0 };
    pieces[11] = { ArrowInHole, CrossPlug, CirclePlug, CircleHole, 0 };
    pieces[12] = { CircleHole, ArrowInPlug, ArrowInPlug, CrossHole, 0 };
    pieces[13] = { CrossHole, ArrowOutPlug, CrossPlug, ArrowInHole, 0 };
    pieces[14] = { ArrowOutHole, CirclePlug, CrossPlug, ArrowOutHole, 0 };
    pieces[15] = { ArrowInPlug, CirclePlug, CrossHole, CircleHole, 0 };


    // start with the first four


    //int TopLeft = 0;
    //int TopRight = 0;
    //int BottomLeft = 0;
    //int BottomRight = 0;


    //for (int TLI = 0; TLI < 16; TLI++)
    //{
    //    TopLeft = TLI;
    //    //if (TLI != TopRight && TLI != 2)
    //    {
    //        for (int TRI = 0; TRI < 16; TRI++)
    //        {
    //            if (TRI != TLI /*&& TRI != BottomLeft && TRI != BottomRight*/)
    //            {
    //                TopRight = TRI;
    //                for (int BLI = 0; BLI < 16; BLI++)
    //                {
    //                    if (BLI != TLI && BLI != TRI /*&& BLI != BottomRight*/)
    //                    {
    //                        BottomLeft = BLI;
    //                        for (int BRI = 0; BRI < 16; BRI++)
    //                        {
    //                            if (BRI != TLI && BRI != TRI && BRI != BLI)
    //                            {
    //                                BottomRight = BRI;
    //                                // try
    //                                for (int r1 = 0; r1 < rotations; r1++)
    //                                {
    //                                    pieces[TopLeft].rotation = r1;
    //                                    for (int r2 = 0; r2 < rotations; r2++)
    //                                    {
    //                                        pieces[TopRight].rotation = r2;
    //                                        for (int r3 = 0; r3 < rotations; r3++)
    //                                        {
    //                                            pieces[BottomLeft].rotation = r3;
    //                                            for (int r4 = 0; r4 < rotations; r4++)
    //                                            {
    //                                                pieces[BottomRight].rotation = r4;
    //                                                if (checkTwoByTwo(pieces[TopLeft], pieces[TopRight], pieces[BottomLeft], pieces[BottomRight]))
    //                                                {
    //                                                    if (setIndex > 10000)
    //                                                    {
    //                                                        int bp = 5;
    //                                                    }
    //                                                    //sets[setIndex] = { pieces[TopLeft], pieces[TopRight], pieces[BottomLeft], pieces[BottomRight] };
    //                                                    indecies[setIndex] = { TopLeft, pieces[TopLeft].rotation,
    //                                                                            TopRight, pieces[TopRight].rotation,
    //                                                                            BottomLeft, pieces[BottomLeft].rotation,
    //                                                                            BottomRight, pieces[BottomRight].rotation };
    //                                                    if (pieces[TopLeft].rotation >= rotations || pieces[TopRight].rotation >= rotations || pieces[BottomLeft].rotation >= rotations || pieces[BottomRight].rotation >= rotations)
    //                                                    {
    //                                                        int bp = 5;
    //                                                    }
    //                                                    setIndex++;
    //                                                    if (setIndex == 1507)
    //                                                    {
    //                                                        int bp = 5;
    //                                                    }
    //                                                }
    //                                            }
    //                                        }
    //                                    }
    //                                }
    //                            }
    //                        }

    //                    }
    //                }
    //            }
    //        }

    //    }
    //}

    for (int TLI = 0; TLI < 16; TLI++)
    {
        for (int r0 = 0; r0 < rotations; r0++)
        {
            for (int TRI = 0; TRI < 16; TRI++)
            {
                if (TRI != TLI)
                {
                    for (int r1 = 0; r1 < rotations; r1++)
                    {
                        if (checkFit(pieces[TLI].getRight(r0), pieces[TRI].getLeft(r1)))// pieces fit together
                        {
                            for (int BLI = 0; BLI < 16; BLI++)
                            {
                                if (BLI != TLI && BLI != TRI)// unique piece
                                {
                                    for (int r2 = 0; r2 < rotations; r2++)
                                    {
                                        if (checkFit(pieces[BLI].getUp(r2), pieces[TLI].getDown(r0)))//pieces fit together
                                        {
                                            for (int BRI = 0; BRI < 16; BRI++)
                                            {
                                                if (BRI != TRI && BRI != TLI && BRI != BLI)
                                                {
                                                    for (int r3 = 0; r3 < rotations; r3++)
                                                    {
                                                        if (checkFit(pieces[BLI].getRight(r2), pieces[BRI].getLeft(r3))
                                                            && checkFit(pieces[TRI].getDown(r1), pieces[BRI].getUp(r3)))
                                                        {
                                                            if (setIndex == 5)
                                                            {
                                                                int bp = 5;
                                                            }
                                                            twos[setIndex] /*= new TwoByTwoIndex();
                                                            *twos[setIndex] */ = { TLI, r0,
                                                                                    TRI, r1,
                                                                                    BLI, r2,
                                                                                    BRI, r3 };
                                                            setIndex++;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }








    // 1508 sets of 2 by 2

    // trying instead to do 3 by 3 next

    {

        //TopRight = 0;
        //int MidRight = 0;
        //BottomLeft = 0;
        //int BottomMid = 0;
        //BottomLeft = 0;

        if (setIndex > 1508)
        {
            int bp = 5;
        }

        for (int i = 0; i < setIndex; i++)
        {
            for (int TRI = 0; TRI < 16; TRI++)
            {
                if (TRI != twos[i].TLIndex && TRI != twos[i].TRIndex && TRI != twos[i].BLIndex && TRI != twos[i].BRIndex // if it is a new piece
                    && i != 4 && i != 5)//debugging, idk why 4 is breaking
                {
                    for (int r0 = 0; r0 < rotations; r0++)
                    {
                        if (checkFit(pieces[twos[i].TRIndex].getRight(twos[i].TRRot), pieces[TRI].getLeft(r0)))// top right fits
                        {
                            for (int MRI = 0; MRI < 16; MRI++)
                            {
                                if (MRI != twos[i].TLIndex && MRI != twos[i].TRIndex && MRI != twos[i].BLIndex && MRI != twos[i].BRIndex
                                    && MRI != TRI)// if it is a new piece
                                {
                                    for (int r1 = 0; r1 < rotations; r1++)
                                    {
                                        if (checkFit(pieces[twos[i].BRIndex].getRight(twos[i].BRRot), pieces[MRI].getLeft(r1))
                                            && checkFit(pieces[TRI].getDown(r0), pieces[MRI].getUp(r1))) // mid right fits
                                        {
                                            for (int BRI = 0; BRI < 16; BRI++)
                                            {
                                                if (BRI != twos[i].TLIndex && BRI != twos[i].TRIndex && BRI != twos[i].BLIndex && BRI != twos[i].BRIndex
                                                    && BRI != MRI && BRI != TRI)// if is a new piece
                                                {
                                                    for (int r2 = 0; r2 < rotations; r2++)
                                                    {
                                                        if (checkFit(pieces[MRI].getDown(r1), pieces[BRI].getUp(r2)))// bottom right fits
                                                        {
                                                            for (int BMI = 0; BMI < 16; BMI++)
                                                            {
                                                                if (BMI != twos[i].TLIndex && BMI != twos[i].TRIndex && BMI != twos[i].BLIndex && BMI != twos[i].BRIndex
                                                                    && BMI != BRI && BMI != MRI && BMI != TRI) // piece is new
                                                                {
                                                                    for (int r3 = 0; r3 < rotations; r3++)
                                                                    {
                                                                        if (checkFit(pieces[twos[i].BRIndex].getDown(twos[i].BRRot), pieces[BMI].getUp(r3))
                                                                            && checkFit(pieces[BRI].getLeft(r2), pieces[BMI].getRight(r3)))// bottom middle fits
                                                                        {
                                                                            for (int BLI = 0; BLI < 16; BLI++)
                                                                            {
                                                                                if (BLI != twos[i].TLIndex && BLI != twos[i].TRIndex && BLI != twos[i].BLIndex && BLI != twos[i].BRIndex
                                                                                    && BLI != BMI && BLI != BRI && BLI != MRI && BLI != TRI)// the piece is new
                                                                                {
                                                                                    for (int r4 = 0; r4 < rotations; r4++)
                                                                                    {
                                                                                        if (checkFit(pieces[twos[i].BLIndex].getDown(twos[i].BLRot), pieces[BLI].getUp(r4))
                                                                                            && checkFit(pieces[BMI].getLeft(r3), pieces[BLI].getRight(r4)))// the piece fits, so does the whole
                                                                                        {
                                                                                            //if (threesIndex > 10000)
                                                                                            //{
                                                                                            //    threes2[threesIndex2] = { indecies[i], TRI, r0, MRI, r1, BRI, r2, BMI, r3, BLI, r4 };
                                                                                            //    threesIndex2++;
                                                                                            //}
                                                                                            //else
                                                                                            {
                                                                                                if (threesIndex < yeah)
                                                                                                {
                                                                                                    threes[threesIndex] = new ThreeByThreeIndex(&(twos[i]), TRI, r0, MRI, r1, BRI, r2, BMI, r3, BLI, r4);
                                                                                                    //*threes[threesIndex] = { &(twos[i]), TRI, r0, MRI, r1, BRI, r2, BMI, r3, BLI, r4 };
                                                                                                    threesIndex++;
                                                                                                }
                                                                                                else
                                                                                                {
                                                                                                    int bp = 5;
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }



    for (int i = 0; i < threesIndex; i++)
    {
        if (i == threesIndex - 1)
        {
            int bp = 5;
        }
        for (int pI0 = 0; pI0 < 16; pI0++)
        {
            if (compareIndexToThrees(pI0, *threes[i]))// it's a new piece
            {
                for (int r0 = 0; r0 < rotations; r0++)
                {
                    if (checkFit(pieces[threes[i]->Index0].getRight(threes[i]->Rot0), pieces[pI0].getLeft(r0)))// top right piece fits
                    {
                        for (int pI1 = 0; pI1 < 16; pI1++)
                        {
                            if (compareIndexToThrees(pI1, *threes[i])
                                && pI1 != pI0)// piece is unique
                            {
                                for (int r1 = 0; r1 < rotations; r1++)
                                {
                                    if (checkFit(pieces[threes[i]->Index1].getRight(threes[i]->Rot1), pieces[pI1].getLeft(r1))
                                        && checkFit(pieces[pI0].getDown(r0), pieces[pI1].getUp(r1)))// top mid right fits
                                    {
                                        for (int pI2 = 0; pI2 < 16; pI2++)
                                        {
                                            if (compareIndexToThrees(pI2, *threes[i])
                                                && pI2 != pI1
                                                && pI2 != pI0)// the piece is unique
                                            {
                                                for (int r2 = 0; r2 < rotations; r2++)
                                                {
                                                    bool debug = checkFit(pieces[threes[i]->Index2].getRight(threes[i]->Rot2), pieces[pI2].getLeft(r2)) && checkFit(pieces[pI1].getDown(r1), pieces[pI2].getUp(r2));
                                                    bool debugA = checkFit(pieces[threes[i]->Index2].getRight(threes[i]->Rot2), pieces[pI2].getLeft(r2));
                                                    bool debugB = checkFit(pieces[pI1].getDown(r1), pieces[pI2].getUp(r2));
                                                    if ((debugA || debugB) && i != 13)
                                                    {
                                                        int bp = 5;
                                                    }
                                                    if (checkFit(pieces[threes[i]->Index2].getRight(threes[i]->Rot2), pieces[pI2].getLeft(r2)) // the farthest it gets
                                                        && checkFit(pieces[pI1].getDown(r1), pieces[pI2].getUp(r2)))// bottom mid right fits
                                                    {
                                                        for (int pI3 = 0; pI3 < 16; pI3++)
                                                        {
                                                            if (compareIndexToThrees(pI3, *threes[i])
                                                                && pI3 != pI2
                                                                && pI3 != pI1
                                                                && pI3 != pI0)
                                                            {
                                                                for (int r3 = 0; r3 < rotations; r3++)
                                                                {
                                                                    if (checkFit(pieces[pI2].getDown(r2), pieces[pI3].getUp(r3)))// bottom right piece fits
                                                                    {
                                                                        for (int pI4 = 0; pI4 < 16; pI4++)
                                                                        {
                                                                            if (compareIndexToThrees(pI4, *threes[i])
                                                                                && pI4 != pI3
                                                                                && pI4 != pI2
                                                                                && pI4 != pI1
                                                                                && pI4 != pI0)// bottom right mid is unique
                                                                            {
                                                                                for (int r4 = 0; r4 < rotations; r4++)
                                                                                {
                                                                                    if (checkFit(pieces[threes[i]->Index2].getDown(threes[i]->Rot2), pieces[pI4].getUp(r4))
                                                                                        && checkFit(pieces[pI3].getLeft(r3), pieces[pI4].getRight(r4)))// bottom right mid fits
                                                                                    {
                                                                                        for (int pI5 = 0; pI5 < 16; pI5++)
                                                                                        {
                                                                                            if (compareIndexToThrees(pI5, *threes[i])
                                                                                                && pI5 != pI4
                                                                                                && pI5 != pI3
                                                                                                && pI5 != pI2
                                                                                                && pI5 != pI1
                                                                                                && pI5 != pI0)// bottom left mid is unique
                                                                                            {
                                                                                                for (int r5 = 0; r5 < rotations; r5++)
                                                                                                {
                                                                                                    if (checkFit(pieces[threes[i]->Index3].getDown(threes[i]->Rot3), pieces[pI5].getUp(r5))
                                                                                                        && checkFit(pieces[pI4].getLeft(r4), pieces[pI5].getRight(r5)))// bottom left middle fits
                                                                                                    {
                                                                                                        for (int pI6 = 0; pI6 < 16; pI6++)
                                                                                                        {
                                                                                                            if (compareIndexToThrees(pI6, *threes[i])
                                                                                                                && pI6 != pI5
                                                                                                                && pI6 != pI4
                                                                                                                && pI6 != pI3
                                                                                                                && pI6 != pI2
                                                                                                                && pI6 != pI1
                                                                                                                && pI6 != pI0)// the piece is unique
                                                                                                            {
                                                                                                                for (int r6 = 0; r6 < rotations; r6++)
                                                                                                                {
                                                                                                                    if (checkFit(pieces[threes[i]->Index4].getDown(threes[i]->Rot4), pieces[pI6].getUp(r6))
                                                                                                                        && checkFit(pieces[pI5].getLeft(r5), pieces[pI6].getRight(r6)))
                                                                                                                    {
                                                                                                                        //solution found!
                                                                                                                        solutions.push_back({

                                                                                                                        threes[i]->Topleft->TLIndex, threes[i]->Topleft->TLRot,
                                                                                                                        threes[i]->Topleft->TRIndex, threes[i]->Topleft->TRRot,
                                                                                                                        threes[i]->Index0, threes[i]->Rot0,
                                                                                                                        pI0, r0,

                                                                                                                        threes[i]->Topleft->BLIndex, threes[i]->Topleft->BLRot,
                                                                                                                        threes[i]->Topleft->BRIndex, threes[i]->Topleft->BRRot,
                                                                                                                        threes[i]->Index1, threes[i]->Rot1,
                                                                                                                        pI1, r1,

                                                                                                                        threes[i]->Index4, threes[i]->Rot4,
                                                                                                                        threes[i]->Index3, threes[i]->Rot3,
                                                                                                                        threes[i]->Index2, threes[i]->Rot2,
                                                                                                                        pI2, r2,

                                                                                                                        pI6, r6,
                                                                                                                        pI5, r5,
                                                                                                                        pI4, r4,
                                                                                                                        pI3, r3


                                                                                                                            });
                                                                                                                        solutionIndex++;
                                                                                                                    }
                                                                                                                }
                                                                                                            }
                                                                                                        }
                                                                                                    }
                                                                                                }
                                                                                            }
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }


    for (int i = 0; i < solutionIndex; i++)
    {
        cout << "Solution #";
        cout << i + 1;
        cout << "\n";
        cout << solutions[i].index0;
        cout << solutions[i].rot0;
        cout << "\t";
        cout << solutions[i].index1;
        cout << solutions[i].rot1;
        cout << "\t";
        cout << solutions[i].index2;
        cout << solutions[i].rot2;
        cout << "\t";
        cout << solutions[i].index3;
        cout << solutions[i].rot3;
        cout << "\n";


        cout << solutions[i].index4;
        cout << solutions[i].rot4;
        cout << "\t";
        cout << solutions[i].index5;
        cout << solutions[i].rot5;
        cout << "\t";
        cout << solutions[i].index6;
        cout << solutions[i].rot6;
        cout << "\t";
        cout << solutions[i].index7;
        cout << solutions[i].rot7;
        cout << "\n";


        cout << solutions[i].index8;
        cout << solutions[i].rot8;
        cout << "\t";
        cout << solutions[i].index9;
        cout << solutions[i].rot9;
        cout << "\t";
        cout << solutions[i].index10;
        cout << solutions[i].rot10;
        cout << "\t";
        cout << solutions[i].index11;
        cout << solutions[i].rot11;
        cout << "\n";


        cout << solutions[i].index12;
        cout << solutions[i].rot12;
        cout << "\t";
        cout << solutions[i].index13;
        cout << solutions[i].rot13;
        cout << "\t";
        cout << solutions[i].index14;
        cout << solutions[i].rot14;
        cout << "\t";
        cout << solutions[i].index15;
        cout << solutions[i].rot15;
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }




    //TopLeft = 0;
    //TopRight = 0;
    //BottomLeft = 0;
    //BottomRight = 0;

    //for (int TLI = 9; TLI < 1508; TLI++)// start at 8, because I already tested up to that
    //{
    //    for (int TRI = 0; TRI < 1508; TRI++)
    //    {
    //        if (TRI != TLI)
    //        {
    //            for (int BLI = 0; BLI < 1508; BLI++)
    //            {
    //                if (BLI != TRI && BLI != TLI)
    //                {
    //                    for (int BRI = 0; BRI < 1508; BRI++)
    //                    {
    //                        if (BRI != BLI && BRI != TRI && BRI != TLI)
    //                        {
    //                            if (checkWholeByTwoByTwo(indecies[TLI], indecies[TRI], indecies[BLI], indecies[BRI]))
    //                            {
    //                                solutions[solutionIndex] = { indecies[TLI], indecies[TRI], indecies[BLI], indecies[BRI] };
    //                                cout << "Solution number ";
    //                                cout << solutionIndex;
    //                                cout << "\n";
    //                                cout << solutions[solutionIndex].TopLeft.TLIndex;
    //                                cout << solutions[solutionIndex].TopLeft.TLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopLeft.TRIndex;
    //                                cout << solutions[solutionIndex].TopLeft.TRRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopLeft.BLIndex;
    //                                cout << solutions[solutionIndex].TopLeft.BLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopLeft.BRIndex;
    //                                cout << solutions[solutionIndex].TopLeft.BRRot;
    //                                cout << "\n";





    //                                cout << solutions[solutionIndex].TopRight.TLIndex;
    //                                cout << solutions[solutionIndex].TopRight.TLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopRight.TRIndex;
    //                                cout << solutions[solutionIndex].TopRight.TRRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopRight.BLIndex;
    //                                cout << solutions[solutionIndex].TopRight.BLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].TopRight.BRIndex;
    //                                cout << solutions[solutionIndex].TopRight.BRRot;
    //                                cout << "\n";







    //                                cout << solutions[solutionIndex].BottomLeft.TLIndex;
    //                                cout << solutions[solutionIndex].BottomLeft.TLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomLeft.TRIndex;
    //                                cout << solutions[solutionIndex].BottomLeft.TRRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomLeft.BLIndex;
    //                                cout << solutions[solutionIndex].BottomLeft.BLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomLeft.BRIndex;
    //                                cout << solutions[solutionIndex].BottomLeft.BRRot;
    //                                cout << "\n";





    //                                cout << solutions[solutionIndex].BottomRight.TLIndex;
    //                                cout << solutions[solutionIndex].BottomRight.TLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomRight.TRIndex;
    //                                cout << solutions[solutionIndex].BottomRight.TRRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomRight.BLIndex;
    //                                cout << solutions[solutionIndex].BottomRight.BLRot;
    //                                cout << "\n";

    //                                cout << solutions[solutionIndex].BottomRight.BRIndex;
    //                                cout << solutions[solutionIndex].BottomRight.BRRot;
    //                                cout << "\n";
    //                                cout << "\n";
    //                                cout << "\n";
    //                                cout << "\n";
    //                                solutionIndex++;
    //                                if (solutionIndex > 1000)
    //                                {
    //                                    int bp = 5;
    //                                }
    //                            }

    //                        }
    //                    }
    //                }
    //            }
    //        }
    //    }
    //}








    //for (int r1 = 0; r1 < 4; r1++)
    //{
    //    pieces[0].rotation = r1;
    //    for (int r2 = 0; r2 < 4; r2++)
    //    {
    //        pieces[1].rotation = r2;
    //        for (int r3 = 0; r3 < 4; r3++)
    //        {
    //            pieces[2].rotation = r3;
    //            for (int r4 = 0; r4 < 4; r4++)
    //            {
    //                pieces[3].rotation = r4;
    //                if (checkTwoByTwo(pieces[0], pieces[1], pieces[2], pieces[3]))
    //                {
    //                    sets[setIndex] = { pieces[0], pieces[1], pieces[2], pieces[3] };
    //                    setIndex++;
    //                }
    //            }
    //        }
    //    }
    //}


    //for (int i = 0; i < 16; i++)
    //{

    //    for (int r = 0; r < 4; r++)
    //    {
    //        pieces[i].rotation = r;

    //    }


    //}


    int  bp = 5;
    // began running solution finder at 8:51 AM STARTDATE

    //delete[] threes;
    //delete[] twos;

    return 0;
}

//Shape Piece::getUp()
//{
//    switch (rotation)
//    {
//    case 0:
//        return up;
//        break;
//    case 1:
//        return left;
//        break;
//    case 2:
//        return down;
//        break;
//    case 3:
//        return right;
//        break;
//    default:
//        return Shape::ERROR;
//    }
//}
//
//Shape Piece::getRight()
//{
//    switch (rotation)
//    {
//    case 0:
//        return right;
//        break;
//    case 1:
//        return up;
//        break;
//    case 2:
//        return left;
//        break;
//    case 3:
//        return down;
//        break;
//    default:
//        return Shape::ERROR;
//    }
//}
//
//Shape Piece::getDown()
//{
//    switch (rotation)
//    {
//    case 0:
//        return down;
//        break;
//    case 1:
//        return right;
//        break;
//    case 2:
//        return up;
//        break;
//    case 3:
//        return left;
//        break;
//    default:
//        return Shape::ERROR;
//    }
//}
//
//Shape Piece::getLeft()
//{
//    switch (rotation)
//    {
//    case 0:
//        return left;
//        break;
//    case 1:
//        return down;
//        break;
//    case 2:
//        return right;
//        break;
//    case 3:
//        return up;
//        break;
//    default:
//        return Shape::ERROR;
//    }
//}

Shape Piece::getUp(int rot)
{
    switch (rot)
    {
    case 0:
        return up;
        break;
    case 1:
        return left;
        break;
    case 2:
        return down;
        break;
    case 3:
        return right;
        break;
    case 4:// flipped on horizontally
        return up;
        break;
    case 5:// flipped vertically
        return down;
        break;
    default:
        return Shape::ERROR;
    }
}

Shape Piece::getRight(int rot)
{
    switch (rot)
    {
    case 0:
        return right;
        break;
    case 1:
        return up;
        break;
    case 2:
        return left;
        break;
    case 3:
        return down;
        break;
    case 4:// flipped on horizontally
        return left;
        break;
    case 5:// flipped vertically
        return right;
        break;
    default:
        return Shape::ERROR;
    }
}

Shape Piece::getDown(int rot)
{
    switch (rot)
    {
    case 0:
        return down;
        break;
    case 1:
        return right;
        break;
    case 2:
        return up;
        break;
    case 3:
        return left;
        break;
    case 4:// flipped on horizontally
        return down;
        break;
    case 5:// flipped vertically
        return up;
        break;
    default:
        return Shape::ERROR;
    }
}

Shape Piece::getLeft(int rot)
{
    switch (rot)
    {
    case 0:
        return left;
        break;
    case 1:
        return down;
        break;
    case 2:
        return right;
        break;
    case 3:
        return up;
        break;
    case 4:// flipped on horizontally
        return right;
        break;
    case 5:// flipped vertically
        return left;
        break;
    default:
        return Shape::ERROR;
    }
}

bool checkTwoByTwo(Piece tl, Piece tr, Piece bl, Piece br)
{
    //bool result = true;

    if (abs(int(tl.getRight(tl.rotation)) - int(tr.getLeft(tr.rotation)) != 1))
    {
        return false;
    }

    if (abs(int(tr.getDown(tr.rotation)) - int(br.getUp(br.rotation))) != 1)
    {
        return false;
    }

    if (abs(int(br.getLeft(br.rotation)) - int(bl.getRight(bl.rotation))) != 1)
    {
        return false;
    }

    if (abs(int(bl.getUp(bl.rotation)) - int(tl.getDown(tl.rotation))) != 1)
    {
        return false;
    }


    return true;
}

bool checkWholeByTwoByTwo(TwoByTwoIndex TL, TwoByTwoIndex TR, TwoByTwoIndex BL, TwoByTwoIndex BR/*, Piece pieces[]*/)
{
    //for (int TLI = 0; TLI < 4; TLI++)
    //{


    //    for (int BRI = 0; BRI < 4; BRI++)
    //    {
    //        if()
    //    }
    //}

    Piece pieces[16];

    pieces[0] = { ArrowOutHole, CrossPlug, ArrowInPlug, ArrowInHole, 0 };
    pieces[1] = { ArrowOutHole, CirclePlug, ArrowInPlug, ArrowInHole, 0 };
    pieces[2] = { ArrowOutHole, ArrowOutPlug, ArrowInPlug, CircleHole, 0 };
    pieces[3] = { CircleHole, CrossPlug, ArrowOutPlug, ArrowOutHole, 0 };
    pieces[4] = { CrossHole, ArrowInPlug, CirclePlug, ArrowInHole, 0 };
    pieces[5] = { CircleHole, CirclePlug, ArrowOutPlug, CrossHole, 0 };
    pieces[6] = { CircleHole, ArrowOutPlug, ArrowOutPlug, ArrowInHole, 0 };
    pieces[7] = { CircleHole, CirclePlug, ArrowOutPlug, ArrowOutHole, 0 };
    pieces[8] = { CircleHole, CirclePlug, CirclePlug, ArrowOutHole, 0 };
    pieces[9] = { ArrowOutHole, ArrowInPlug, ArrowInPlug, CrossHole, 0 };
    pieces[10] = { CircleHole, CirclePlug, CrossPlug, CrossHole, 0 };
    pieces[11] = { ArrowInHole, CrossPlug, CirclePlug, CircleHole, 0 };
    pieces[12] = { CircleHole, ArrowInPlug, ArrowInPlug, CrossHole, 0 };
    pieces[13] = { CrossHole, ArrowOutPlug, CrossPlug, ArrowInHole, 0 };
    pieces[14] = { ArrowOutHole, CirclePlug, CrossPlug, ArrowOutHole, 0 };
    pieces[15] = { ArrowInPlug, CirclePlug, CrossHole, CircleHole, 0 };


    int TopLeft[4] = { TL.TLIndex, TL.TRIndex, TL.BLIndex, TL.BRIndex };
    int TopRight[4] = { TR.TLIndex, TR.TRIndex, TR.BLIndex, TR.BRIndex };
    int BotLeft[4] = { BL.TLIndex, BL.TRIndex, BL.BLIndex, BL.BRIndex };
    int BotRight[4] = { BR.TLIndex, BR.TRIndex, BR.BLIndex, BR.BRIndex };

    for (int TLI = 0; TLI < 4; TLI++)
    {
        for (int TRI = 0; TRI < 4; TRI++)
        {
            if (TopLeft[TLI] == TopRight[TRI])
            {
                return false;
            }
        }
        for (int BLI = 0; BLI < 4; BLI++)
        {
            if (TopLeft[TLI] == BotLeft[BLI])
            {
                return false;
            }
        }
        for (int BRI = 0; BRI < 4; BRI++)
        {
            if (TopLeft[TLI] == BotRight[BRI])
            {
                return false;
            }
        }
    }

    for (int TRI = 0; TRI < 4; TRI++)
    {
        for (int BLI = 0; BLI < 4; BLI++)
        {
            if (TopRight[TRI] == BotLeft[BLI])
            {
                return false;
            }
        }
        for (int BRI = 0; BRI < 4; BRI++)
        {
            if (TopRight[TRI] == BotRight[BRI])
            {
                return false;
            }
        }
    }

    for (int BLI = 0; BLI < 4; BLI++)
    {
        for (int BRI = 0; BRI < 4; BRI++)
        {
            if (BotLeft[BLI] == BotRight[BRI])
            {
                return false;
            }
        }
    }




    // 8 seams to check


    //if (abs(int(TL.TRIndex.getRight()) - int(tr.getLeft()) != 1))
    // top out
    if (abs(int(pieces[TL.TRIndex].getRight(TL.TRRot)) - int(pieces[TR.TLIndex].getLeft(TR.TLRot)) != 1)) // +
    {
        return false;
    }

    // top in
    if (abs(int(pieces[TL.BRIndex].getRight(TL.BRRot)) - int(pieces[TR.BLIndex].getLeft(TR.BLRot)) != 1)) // +
    {
        return false;
    }


    // right out
    if (abs(int(pieces[TR.BRIndex].getDown(TR.BRRot)) - int(pieces[BR.TRIndex].getUp(BR.TRRot)) != 1)) // +
    {
        return false;
    }

    // right in
    if (abs(int(pieces[TR.BLIndex].getDown(TR.BLRot)) - int(pieces[BR.TLIndex].getUp(BR.TLRot)) != 1)) // +
    {
        return false;
    }


    // bot out
    if (abs(int(pieces[BR.BLIndex].getLeft(BR.BLRot)) - int(pieces[BL.BRIndex].getRight(BL.BRRot)) != 1)) // +
    {
        return false;
    }

    // bot in
    if (abs(int(pieces[BR.TLIndex].getLeft(BR.TLRot)) - int(pieces[BL.TRIndex].getRight(BL.TRRot)) != 1)) // +
    {
        return false;
    }


    // left out
    if (abs(int(pieces[BL.TLIndex].getUp(BL.TLRot)) - int(pieces[TL.BLIndex].getDown(TL.BLRot)) != 1)) // +
    {
        return false;
    }

    // left in
    if (abs(int(pieces[BL.TRIndex].getUp(BL.TRRot)) - int(pieces[TL.BRIndex].getDown(TL.BRRot)) != 1)) // +
    {
        return false;
    }


    return true;
}

bool checkFit(Shape a, Shape b)
{
    if (a == Shape::ERROR || b == Shape::ERROR)
    {
        int bp = 5;
    }
    bool result = abs(int(a) - int(b)) == 1;
    return result;
}

void doSpins(Piece tl, Piece tr, Piece bl, Piece br)
{
    for (int r1 = 0; r1 < 4; r1++)
    {
        tl.rotation = r1;
        for (int r2 = 0; r2 < 4; r2++)
        {
            tr.rotation = r2;
            for (int r3 = 0; r3 < 4; r3++)
            {
                bl.rotation = r3;
                for (int r4 = 0; r4 < 4; r4++)
                {
                    br.rotation = r4;
                    if (checkTwoByTwo(tl, tr, bl, br))
                    {
                        //sets[setIndex] = { pieces[0], pieces[1], pieces[2], pieces[3] };
                        //setIndex++;
                    }
                }
            }
        }
    }
}

bool compareIndexToThrees(int index, ThreeByThreeIndex three)
{
    //pI0 != threes[i].Topleft.TLIndex && pI0 != threes[i].Topleft.TRIndex && pI0 != threes[i].Topleft.BLIndex && pI0 != threes[i].Topleft.BLIndex
    bool result = true;
    if (index == three.Topleft->TLIndex || index == three.Topleft->TRIndex || index == three.Topleft->BLIndex || index == three.Topleft->BRIndex)
    {
        result = false;
    }
    if (index == three.Index0 || index == three.Index1 || index == three.Index2 || index == three.Index3 || index == three.Index4)
    {
        result = false;
    }
    return result;
}
