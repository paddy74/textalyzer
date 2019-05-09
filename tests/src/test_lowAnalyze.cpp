#include <iostream>
#include <textalyzer/Analyzer.hpp>


int main()
{
    std::string testStr =
        "In God's name what does this mean? Harker cried out. Dr. "
        "Seward, Dr. Van Helsing, what is it? What has happened? What is "
        "wrong? Mina, dear, what is it? What does that blood mean? My "
        "God, my God! has it come to this! and, raising himself to his "
        "knees, he beat his hands wildly together. Good God help us! "
        "help her! oh, help her! With a quick movement he jumped from "
        "bed, and began to pull on his clothes,--all the man in him "
        "awake at the need for instant exertion. What has happened? Tell "
        "me all about it! he cried without pausing. Dr. Van Helsing, you "
        "love Mina, I know. Oh, do something to save her. It cannot have "
        "gone too far yet. Guard her while I look for him! His wife, "
        "through her terror and horror and distress, saw some sure "
        "danger to him: instantly forgetting her own grief, she seized "
        "hold of him and cried out: No! no! Jonathan, you must not leave "
        "me. I have suffered enough to-night, God knows, without the "
        "dread of his harming you. You must stay with me. Stay with "
        "these friends who will watch over you! Her expression became "
        "frantic as she spoke; and, he yielding to her, she pulled him "
        "down sitting on the bed side, and clung to him fiercely. Van "
        "Helsing and I tried to calm them both. The Professor held up "
        "his little golden crucifix, and said with wonderful calmness: "
        "Do not fear, my dear. We are here; and whilst this is close to "
        "you no foul thing can approach. You are safe for to-night; and "
        "we must be calm and take counsel together. She shuddered and "
        "was silent, holding down her head on her husband's breast. When "
        "she raised it, his white night-robe was stained with blood "
        "where her lips had touched, and where the thin open wound in "
        "her neck had sent forth drops. The instant she saw it she drew "
        "back, with a low wail, and whispered, amidst choking sobs: "
        "Unclean, unclean! I must touch him or kiss him no more. Oh, "
        "that it should be that it is I who am now his worst enemy, and "
        "whom he may have most cause to fear. To this he spoke out "
        "resolutely: Nonsense, Mina. It is a shame to me to hear such a "
        "word. I would not hear it of you; and I shall not hear it from "
        "you. May God judge me by my deserts, and punish me with more "
        "bitter suffering than even this hour, if by any act or will of "
        "mine anything ever come between us! He put out his arms and "
        "folded her to his breast; and for a while she lay there "
        "sobbing. He looked at us over her bowed head, with eyes that "
        "blinked damply above his quivering nostrils; his mouth was set "
        "as steel. After a while her sobs became less frequent and more "
        "faint, and then he said to me, speaking with a studied calmness "
        "which I felt tried his nervous power to the utmost:-- And now, "
        "Dr. Seward, tell me all about it. Too well I know the broad "
        "fact; tell me all that has been. I told him exactly what had "
        "happened, and he listened with seeming impassiveness; but his "
        "nostrils twitched and his eyes blazed as I told how the "
        "ruthless hands of the Count had held his wife in that terrible "
        "and horrid position, with her mouth to the open wound in his "
        "breast. It interested me, even at that moment, to see, that, "
        "whilst the face of white set passion worked convulsively over "
        "the bowed head, the hands tenderly and lovingly stroked the "
        "ruffled hair. Just as I had finished, Quincey and Godalming "
        "knocked at the door. They entered in obedience to our summons. "
        "Van Helsing looked at me questioningly. I understood him to "
        "mean if we were to take advantage of their coming to divert if "
        "possible the thoughts of the unhappy husband and wife from each "
        "other and from themselves; so on nodding acquiescence to him he "
        "asked them what they had seen or done. To which Lord Godalming "
        "answered: I could not see him anywhere in the passage, or in "
        "any of our rooms. I looked in the study but, though he had been "
        "there, he had gone. He had, however---- He stopped suddenly, "
        "looking at the poor drooping figure on the bed. Van Helsing "
        "said gravely:--";

    auto const anlyzPair = textalyzer::Analyzer::lowAnalyze(testStr, 2);

    std::cout << "Test: lowAnalyze\n----------------\n";
    std::cout << "Number of words: " << anlyzPair.second << std::endl << "[";
    for (auto const & item : anlyzPair.first) std::cout << item << ", ";
    std::cout << "]" << std::endl;

    return 0;
}
