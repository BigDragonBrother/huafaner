<?php
include_once PATH_BLL . '/userBll.inc';

$cust_list = userBll::getCustByuserid($_COOKIE['user_id']);
$cust=array();
?>
<div class="ind_main" style="margin-top:15px;">
    <h1>收花人地址</h1>
    <div class="detailed_info">
        <form>
            <div class="edit">
                <h4 class="line">我的收花人地址</h4>
                <ul>
                    <?php
                    if(count($cust_list)==0)
                    {
                        echo "<li>还没有收花人地址？现在就<a href=\"javascript:void(0)\" onclick=\"$('#cust_title').focus();\">添加</a></li>";
                    }
                    foreach ($cust_list as $k => $v) {
                        echo '<li><b>', $v['cust_name'], ',', $v['cust_title'], ',', $v['cust_province'], ',', $v['cust_city'], ',',
                        $v['cust_town'], ',', $v['cust_address'], ',',$v['cust_tel'],"</b><i>",
                        $v['cust_default']==1?"<a class=\"gray\"":"<a href=\"javascript:void(0)\" onclick=\"setDefaultCust(".$v['cust_id'].','.$v['user_id'].")\"",
                        ">设置为默认地址</a><a href=\"user.php?m=user_addr&cust_id=",$v['cust_id'],
                        "\">修改</a><a href=\"javascript:void(0)\" onclick=\"delCust(",$v['cust_id'],")\">删除</a></i></li>";
                        
                        if($v['cust_id']==Tools::getValue("cust_id"))
                        {
                            $cust=$v;
                        }
                    }
                    ?>
                </ul>
                <h4 class="line">管理我的收花人地址</h4>
                <dl class="input_list pad_bnone">
                    <dd>
                        <label for="b1">称谓*</label>
                        <select name="cust_title" id="cust_title">
                            <option value="0">请选择</option>
                            <option value="小姐" <?php if(!empty($cust)){echo $cust['cust_title']=='小姐'?'selected':'';} ?>>小姐</option>
                            <option value="女士" <?php if(!empty($cust)){echo $cust['cust_title']=='女士'?'selected':'';} ?>>女士</option>
                            <option value="先生" <?php if(!empty($cust)){echo $cust['cust_title']=='先生'?'selected':'';} ?>>先生</option>
                        </select>
                        <div class="form_error" id="cust_title_error" style="display:none">收花人怎么称呼</div>
                    </dd>
                    <dd>
                        <input type="hidden" id="user_id" name="user_id" value="<?php echo $_COOKIE['user_id']; ?>" />
                        <input type="hidden" id="cust_id" name="cust_id" value="<?php echo Tools::getValue("cust_id"); ?>" />
                        <label for="b1">姓名*</label>
                        <input name="cust_name" type="text" id="cust_name" class="inputtext sty160" value="<?php echo empty($cust)?'':$cust['cust_name']; ?>"/>
                        <div class="form_error" id="cust_name_error" style="display:none">收花人是要有名字的</div>
                    </dd>
                    <dd>
                        <label for="b2">省市区县*</label>
                        <select name="cust_province" id="cust_province" class="">
                            <option value="0">请选择省</option>
                            <option value="北京">北京</option>
                        </select>
                        <select name="cust_city" id="cust_city" class="">
                            <option value="0">请选择市</option>
                            <option value="北京">北京</option>
                        </select>
                        <select name="cust_town" id="cust_town" class="">
                               <option value="0">请选择区</option>
                                <option value="东城">东城</option>
                                <option value="西城">西城</option>
                                <option value="朝阳">朝阳</option>
                                <option value="丰台">丰台</option>
                                <option value="石景山">石景山</option>
                                <option value="海淀">海淀</option>
                                <option value="门头沟">门头沟</option>
                                <option value="房山">房山</option>
                                <option value="通州">通州</option>
                                <option value="顺义">顺义</option>
                                <option value="昌平">昌平</option>
                                <option value="大兴">大兴</option>
                                <option value="怀柔">怀柔</option>
                                <option value="平谷">平谷</option>
                                <option value="密云">密云</option>
                                <option value="延庆">延庆</option>
                                <option value="开发区">开发区</option>
                        </select>
                        <div class="form_error mar_l" id="cust_province_error" style="display:none">请选择省市区</div>
                    </dd>
                    <dd>
                        <label for="b2">详细地址*</label>
                        <input name="cust_address" id="cust_address" type="text" class="inputtext sty360" value="<?php echo empty($cust)?'':$cust['cust_address']; ?>"/>
                        <div class="form_error" id="cust_address_error" style="display:none">地址信息不能为空</div>
                    </dd>
                    <dd>
                        <label for="b3">联系电话*</label>
                        <input name="cust_tel" id="cust_tel" type="text" id="b3" class="inputtext sty160" value="<?php echo empty($cust)?'':$cust['cust_tel']; ?>"/>
                        <div class="form_error" id="cust_tel_error" style="display:none">我们需要收花人的电话联系TA</div>
                        <div class="form_error" id="cust_tel_error1" style="display:none">请填写正确电话</div>
                    </dd>
                    <dd class="pad_left">
                        <input name="cust_default" id="cust_default" type="checkbox" value="1" <?php echo !empty($cust)&isset($cust['cust_default'])?'checked':''; ?> />
                        <label>设置为默认地址</label>
                    </dd>
                </dl>
                <div class="editbuy">
                    <a href="javascript:void(0)" onclick="CustAdd()" class="sty120"><p>确   定</p></a>
                    <div id="cust_error" class="form_error" style="display:none">对不起，最多能添加5个收花人地址</div>
                    <div id="cust_error1" class="form_error" style="display:none">添加失败</div>
                </div>
            </div>
        </form>
    </div>
</div>
<div class="clearer"></div>
